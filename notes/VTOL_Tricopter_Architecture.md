# VTOL Tricopter Architecture (Historical)

**Status:** Retired airframe. The code and architecture remain active — `ENABLE_TRICOPTER_VTOL_BACKEND` is still the feature flag used by the Avatar build.
**Evolved into:** Avatar tilt-rotor fixed-wing (`Avatar_Design.md`)

---

## 1. System Architecture

The VTOL tricopter used a three-tier distributed control system:

- **PFC (ArduPilot, MicoAir H743):** "Dumb state broadcaster." Runs standard QuadPlane flight stack. Does not understand VTOL mechanics — it intercepts standard ArduPilot outputs and broadcasts them over SBUS. All complex blending and actuation logic lives downstream.
- **TVC (custom firmware, separate MCU):** "Blended angle controller." Sole authority on rotor angles. Reads transition progress from PFC, blends hover vs. forward-flight angle commands, and broadcasts blended vectors to SFCs.
- **SFCs (ESP32-S3, one per motor pod):** "Smart final blenders." Receive state from PFC and angle commands from TVC. Perform the final thrust model blend (`pfc_base_throttle` vs. `plane_throttle`) and apply thrust compensation (`1/cos(angle)` in hover vs. none in forward flight).

---

## 2. PFC Implementation

All modifications are in the `ArduPlane` build target, gated behind:

```cpp
// libraries/AP_CustomConfig/AP_CustomConfig.h
#define ENABLE_TRICOPTER_VTOL_BACKEND 1
```

### 2.1 Backend Initialization

`QuadPlane::setup()` (in `ArduPlane/quadplane.cpp`) forces the custom 6DOF backend when the flag is set:

```cpp
#if ENABLE_TRICOPTER_VTOL_BACKEND
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
#endif
```

Lateral control is disabled (`set_lateral_enable(false)`) — the tricopter is a 5-DOF system.

### 2.2 Motor Mixer

Defined in `AP_Motors6DOF::setup_motors()` in `libraries/AP_Motors/AP_Motors6DOF.cpp`. Five conceptual outputs:

```cpp
#if ENABLE_TRICOPTER_VTOL_BACKEND
    // Motor 1: Front-Right — roll + pitch + throttle
    add_motor_raw_6dof(AP_MOTORS_MOT_1, -1.0f, 0.5f, 0, 1.0f, 0, 0, 1);
    // Motor 2: Front-Left — roll + pitch + throttle
    add_motor_raw_6dof(AP_MOTORS_MOT_2,  1.0f, 0.5f, 0, 1.0f, 0, 0, 2);
    // Motor 3: Rear — pitch (amplified) + throttle
    add_motor_raw_6dof(AP_MOTORS_MOT_3,  0, -TRICOPTER_REAR_PITCH_AMPLIFICATION, 0, 1.0f, 0, 0, 3);
    // Motor 4: Yaw servo (tail)
    add_motor_raw_6dof(AP_MOTORS_MOT_4,  0, 0, 1.0f, 0, 0, 0, 4);
    // Motor 5: Forward thrust command (abstract)
    add_motor_raw_6dof(AP_MOTORS_MOT_5,  0, 0, 0, 0, 1.0f, 0, 5);
#endif
```

### 2.3 State Broadcasting

The PFC "pushes" transition state down to the motors library. In `QuadPlane::update()`:

```cpp
#if ENABLE_TRICOPTER_VTOL_BACKEND
    float transition_progress = 1.0f - ((SLT_Transition*)transition)->transition_mix;
    int16_t plane_throttle_scaled = SRV_Channels::get_output_scaled(SRV_Channel::k_throttle);
    ((AP_Motors6DOF*)motors)->set_vtol_state(transition_progress, plane_throttle_scaled);
#endif
```

`output_armed_stabilizing()` then populates the SBUS output array from those stored values.

### 2.4 SBUS Output Channel Map (Bus A)

| Ch | Signal | Source |
|----|--------|--------|
| 1 | Front-Right `base_throttle` | 6DOF hover controller |
| 2 | Front-Left `base_throttle` | 6DOF hover controller |
| 3 | Rear `base_throttle` | 6DOF hover controller |
| 4 | Yaw servo command | 6DOF yaw mixer |
| 5 | Forward thrust command | Fixed-wing controller |
| 8 | `hover_forward_cmd` | Raw pilot input |
| 11 | `transition_progress` | QuadPlane state machine (inverted) |
| 12 | `plane_throttle_cmd` | Fixed-wing controller |

### 2.5 Thrust Compensation Bypass

The TVC handles all thrust compensation downstream. PFC compensation is bypassed:

```cpp
if (!CATERPILLAR_H_FRAME_6DOF && !ENABLE_TRICOPTER_VTOL_BACKEND) {
    compensation_gain = thr_lin.get_compensation_gain();
}
```

---

## 3. Build Configuration

This is an `ArduPlane` feature — it will not compile for `ArduCopter`.

The `AC_AttitudeControl_Multi_6DoF` class is only compiled when scripting is enabled. Enabling scripting increases firmware size, so an unused feature must be disabled to fit within 2 MB on the MicoAir H743.

```bash
./waf configure --board MicoAir743 --enable-scripting --disable-crsf
./waf plane
```

---

## 4. Hardware & Integration Lessons

### 4.1 DShot / PWM Timer Conflict (H743)

ArduPilot determines output protocol per timer group. DShot and PWM cannot share a timer.

- MicoAir H743 Group 1 (TIM1): Pins 1–4 → **DShot only**
- MicoAir H743 Group 2 (TIM3): Pins 5–6 → **PWM servos only**

Critical params:
- `SERVO_BLH_MASK = 15` — enable DShot for outputs 1–4 only
- `SERVO_BLH_AUTO = 0` — disable auto-detection to prevent accidental DShot on servos

### 4.2 Waf Build System: Subdirectory Limitation

`ardupilotwaf` does **not** recursively scan subdirectories inside `libraries/`. Source files must reside in the library root (e.g., `libraries/AP_Motors/`). Moving `.cpp` files into a subdirectory (e.g., `TVC/`) causes linker errors (`undefined reference`).

### 4.3 TVC Integration into AP_Motors

The TVC brain (`custom_main` logic) was integrated directly into `AP_Motors6DOF::output_armed_stabilizing()`. This allows advanced vectoring math (trigonometry, PIDs, vector normalization) to run inside the standard ArduPilot motors abstraction layer rather than as a separate code path.

### 4.4 270-Degree Vectoring & Pitch Compensation

`atan2(forward, vertical)` handles a full 360° circle naturally. For servo output (0–180° range), piecewise normalization maps the physical angle range (-135° to +180°) to a -1.0 to +1.0 control signal. Adding AHRS pitch (`current_pitch_deg`) to the target angle before normalization keeps the thrust vector ground-relative regardless of airframe pitch.

This pitch compensation is also the stall-prevention mechanism — carried forward into the Avatar design unchanged.

---

## 5. Evolution to Avatar

The Avatar reuses the entire PFC architecture:
- Same `ENABLE_TRICOPTER_VTOL_BACKEND` flag
- Same `QuadPlane::setup()` backend initialization
- Same `AP_Motors6DOF` dispatch pattern
- Same `tvc_run_main_logic` TVC brain with pitch compensation

The tricopter had 3 motor pods on a rotor-tilt mechanism. The Avatar replaces these with tilting wings on a fixed-wing airframe. See `Avatar_Design.md` for current implementation.
