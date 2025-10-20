# Design Document: PFC Modifications for VTOL Tricopter

**Version:** 1.0
**Status:** Implemented

## 1.0 Objective & System Overview

This document details the specific software modifications made to the Primary Flight Controller (PFC) to support a custom, servo-driven, tilt-rotor VTOL tricopter. The design follows a distributed architecture where the PFC's primary role is to act as a "state broadcaster," providing high-level commands and state information to downstream controllers (TVC and SFCs) which handle the complex actuation and blending logic.

All modifications are contained within the `ArduPlane` build target and are activated by the `ENABLE_TRICOPTER_VTOL_BACKEND` feature flag.

## 2.0 Core Architectural Principle: The PFC as a "Dumb" Broadcaster

The fundamental principle of this design is that the PFC is not aware of the specific VTOL mechanics. It runs a standard `QuadPlane` flight stack. All custom modifications are a thin, non-invasive layer that intercepts the standard outputs of the ArduPilot controllers and broadcasts them in a custom SBUS format. This ensures maximum decoupling from the core ArduPilot codebase.

## 3.0 Implementation Details

### 3.1. Master Feature Flag

A new feature flag has been added to `ArduCopter/custom_config.h` to control the entire feature set:

```cpp
// ArduCopter/custom_config.h
#define ENABLE_TRICOPTER_VTOL_BACKEND 1
```

### 3.2. Forcing the Custom Backend

To ensure the correct motor and attitude controllers are used, the `QuadPlane::setup()` function in `ArduPlane/quadplane.cpp` has been modified. When the feature flag is enabled, the default allocation logic is bypassed, and our custom 6-DOF backend is forced.

```cpp
// ArduPlane/quadplane.cpp in QuadPlane::setup()

#if ENABLE_TRICOPTER_VTOL_BACKEND
    // force the motor and attitude control backend for the VTOL tricopter
    motors = NEW_NOTHROW AP_Motors6DOF(rc_speed);
    motors_var_info = AP_Motors6DOF::var_info;
    ahrs_view = ahrs.create_view(ROTATION_NONE, ahrs_trim_pitch);
    attitude_control = NEW_NOTHROW AC_AttitudeControl_Multi_6DoF(*ahrs_view, aparm, *motors);
    attitude_control_var_info = AC_AttitudeControl_Multi_6DoF::var_info;
    ((AC_AttitudeControl_Multi_6DoF*)attitude_control)->set_lateral_enable(false);
    pos_control = NEW_NOTHROW AC_PosControl(*ahrs_view, inertial_nav, *motors, *attitude_control);
    wp_nav = NEW_NOTHROW AC_WPNav(inertial_nav, *ahrs_view, *pos_control, *attitude_control);
    loiter_nav = NEW_NOTHROW AC_Loiter(inertial_nav, *ahrs_view, *pos_control, *attitude_control);
    weathervane = NEW_NOTHROW AC_WeatherVane();
#else
    // ... original allocation logic ...
#endif
```

### 3.3. Disabling Lateral Control

The tricopter airframe is a 5-DOF system and cannot move laterally. The logic above includes a call to `((AC_AttitudeControl_Multi_6DoF*)attitude_control)->set_lateral_enable(false);` to correctly inform the 6-DOF attitude controller of this constraint, preventing it from commanding lateral movements.

### 3.4. Custom Motor Mixer

The motor mixer is defined in `libraries/AP_Motors/AP_Motors6DOF.cpp` within the `setup_motors()` function. It defines 5 conceptual outputs:

1.  **Front-Right Motor:** Provides roll, pitch, and throttle.
2.  **Front-Left Motor:** Provides roll, pitch, and throttle.
3.  **Rear Motor:** Provides pitch (with amplification) and throttle.
4.  **Yaw Servo:** Provides yaw control.
5.  **Forward Thrust:** An abstract output representing the desired forward command.

```cpp
// libraries/AP_Motors/AP_Motors6DOF.cpp in setup_motors()

#if ENABLE_TRICOPTER_VTOL_BACKEND
    // --- Tricopter VTOL Motor Setup ---
    _frame_class_string = "TRICOPTER_VTOL";

    // Define factors for clarity based on ArduPilot conventions.
    // Positive roll command is roll right -> right motors decrease thrust.
    // Positive pitch command is pitch down -> front motors increase thrust.
    const float rollRightFactor = -1.0f;
    const float rollLeftFactor  =  1.0f;
    const float pitchDownFactor =  1.0f; // Front motors get positive factor for pitch down
    const float pitchUpFactor   = -1.0f; // Rear motor gets negative factor for pitch down
    const float yawFactor       =  1.0f;
    const float forwardFactor   =  1.0f;
    const float motorThrottleFactor = 1.0f; // Main thrusting motors contribute 100% to throttle.
    const float noInput         =  0.0f;

    // Motor 1: Front-Right
    add_motor_raw_6dof(AP_MOTORS_MOT_1,  rollRightFactor,  pitchDownFactor * 0.5f, noInput, motorThrottleFactor, noInput, noInput, 1);
    // Motor 2: Front-Left
    add_motor_raw_6dof(AP_MOTORS_MOT_2,  rollLeftFactor,   pitchDownFactor * 0.5f, noInput, motorThrottleFactor, noInput, noInput, 2);
    // Motor 3: Rear
    add_motor_raw_6dof(AP_MOTORS_MOT_3,  noInput,          pitchUpFactor * TRICOPTER_REAR_PITCH_AMPLIFICATION, noInput, motorThrottleFactor, noInput, noInput, 3);
    // Motor 4: Yaw "Motor" (Tail Servo)
    add_motor_raw_6dof(AP_MOTORS_MOT_4,  noInput,  noInput, yawFactor, 0.0f, noInput, noInput, 4);
    // Motor 5: Forward "Motor" (Abstract Forward Thrust Command)
    add_motor_raw_6dof(AP_MOTORS_MOT_5,  noInput,  noInput, noInput, 0.0f, forwardFactor, noInput, 5);
    set_initialised_ok(true);
    return;
#endif
```

### 3.5. State Broadcasting (Architecturally Correct Method)

To avoid breaking architectural layers, the PFC "pushes" state information down to the motors library.

1.  **Interface:** A new public method, `set_vtol_state()`, was added to the `AP_Motors6DOF` class to accept the transition data.
2.  **Data Passing:** In `ArduPlane/quadplane.cpp`, the main `QuadPlane::update()` loop calls this new method on every iteration, passing the `transition_mix` and `plane_throttle_scaled` down to the motors object.
3.  **SBUS Output:** The `output_armed_stabilizing()` function in `AP_Motors6DOF.cpp` then reads these stored member variables and populates the SBUS output array.

```cpp
// ArduPlane/quadplane.cpp in QuadPlane::update()

#if ENABLE_TRICOPTER_VTOL_BACKEND
        // pass transition state to motors library
        float transition_progress = 1.0f - ((SLT_Transition*)transition)->transition_mix;
        int16_t plane_throttle_scaled = SRV_Channels::get_output_scaled(SRV_Channel::k_throttle);
        ((AP_Motors6DOF*)motors)->set_vtol_state(transition_progress, plane_throttle_scaled);
#endif
```

### 3.6. Bypassing PFC Thrust Compensation

The downstream TVC is responsible for all thrust compensation. The PFC's internal compensation has been bypassed for this airframe by modifying the conditional check in `AP_Motors6DOF.cpp`:

```cpp
// libraries/AP_Motors/AP_Motors6DOF.cpp in output_armed_stabilizing()

if(!CATERPILLAR_H_FRAME_6DOF && !ENABLE_TRICOPTER_VTOL_BACKEND) {
  compensation_gain = thr_lin.get_compensation_gain();
}
```

## 4.0 Build System & Dependencies

This feature has critical build system dependencies that must be understood to compile successfully.

### 4.1. Build Target

This is an `ArduPlane` feature. It **will not compile** for `ArduCopter`. The firmware must be built using:
`./waf plane`

### 4.2. `AP_SCRIPTING_ENABLED` Dependency

The custom backend relies on the `AC_AttitudeControl_Multi_6DoF` class. The source file for this class (`AC_AttitudeControl_Multi_6DoF.cpp`) is only compiled if `AP_SCRIPTING_ENABLED` is true. Failure to enable scripting will result in a linker error (`undefined reference to vtable for AC_AttitudeControl_Multi_6DoF`).

### 4.3. Firmware Size and Build Configuration

Enabling scripting significantly increases the firmware size. For the MicoAir743 board, this will cause an "out of memory" linker error (`cannot move location counter backwards`) if other features are not disabled to make space.

The correct and validated method to build this firmware is to **enable scripting** while simultaneously **disabling another large, unused feature** (such as CRSF telemetry).

**Correct Configure Command:**
```bash
./waf configure --board MicoAir743 --enable-scripting --disable-crsf
```
**Correct Build Command:**
```bash
./waf plane
```

## 5.0 Downstream Integration Plan

The PFC is now correctly configured as a "tricopter state broadcaster." The final step is to ensure the downstream TVC and SFCs are correctly configured to consume this new data stream. Based on existing, validated features in the TVC and SFC firmware, this is a **configuration task, not a code development task.**

### 5.1. PFC SBUS Output Mapping

The PFC now broadcasts the following abstract commands on SBUS Bus A:
-   **Ch 1:** Front-Right Motor (`base_throttle`)
-   **Ch 2:** Front-Left Motor (`base_throttle`)
-   **Ch 3:** Rear Motor (`base_throttle`)
-   **Ch 4:** Yaw Servo Command
-   **Ch 5:** Forward Thrust Command
-   **Ch 8:** Pilot `hover_forward_cmd`
-   **Ch 11:** `transition_progress`
-   **Ch 12:** `plane_throttle_cmd`

### 5.2. TVC Integration (No Changes Required)

The TVC requires **no code changes**. Its logic for VTOL mode, as documented in `design_vtol_tricopter.md`, bypasses the old 6-pod saturation model. It relies on pilot commands and transition state, which the PFC continues to provide on the correct channels.

### 5.3. SFC Integration (Configuration Only)

The existing SFC firmware is sufficient but must be configured correctly for each of the three motor pods.

#### 5.3.1. Front Pods (x2, SFC_MODE_VTOL)

The two front SFCs will run in the standard `SFC_MODE_VTOL`. Their configuration must be updated to listen to the correct `base_throttle` channel from the PFC's new tricopter mix.

-   **Front-Right SFC:** Set `SFC_ID` or equivalent mapping to listen for `base_throttle` on **SBUS Channel 1**.
-   **Front-Left SFC:** Set `SFC_ID` or equivalent mapping to listen for `base_throttle` on **SBUS Channel 2**.

These SFCs will continue to listen to the TVC on Bus B for the blended servo angle commands to drive their tilt mechanisms.

#### 5.3.2. Rear Pod (x1, SFC_MODE_PASSTHROUGH)

The single rear SFC will run in `SFC_MODE_PASSTHROUGH`, as documented in `design_sfc_passthrough_mode.md`. Its configuration must be set up to map the PFC's rear-specific channels to its physical actuators.

-   **Mapping 1:** Map the PFC's "Rear Motor" command (**SBUS Channel 3**) to the SFC's physical motor output.
-   **Mapping 2:** Map the PFC's "Yaw Servo Command" (**SBUS Channel 4**) to the SFC's physical servo output.

This correctly translates the PFC's abstract commands into the physical actions required for the tail assembly.
