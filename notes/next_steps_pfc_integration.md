# Design & Implementation Plan: PFC Modifications for VTOL Tricopter

**Version:** 1.0
**Status:** Planning

## 1.0 Objective

This document outlines the necessary software modifications for the Primary Flight Controller (PFC) to support the VTOL Tricopter architecture. The primary goal is to enable the PFC to act as a "state broadcaster," sending all necessary stabilization, transition, and pilot command information to the downstream TVC and SFCs via a custom SBUS protocol.

This plan explicitly accounts for the fact that a new, custom ArduPilot motor backend is required and that the rear motor's yaw control behavior needs to be defined.

## 2.0 Architectural Principle: The PFC as a "Dumb" Broadcaster

It is critical to reiterate that the PFC's role is **not** to understand the specifics of the tilt-rotor mechanism. It should run a standard `QuadPlane` flight stack. Our modifications should be a thin, non-invasive layer that intercepts the standard outputs of the ArduPilot controllers and broadcasts them in our custom SBUS format. All complex blending and actuation logic resides on the TVC and SFCs.

## 3.0 Implementation Plan

### Step 1: Create a Custom Motor Backend

A new motor backend is required to house our custom SBUS output logic.

1.  **Create New Files:**
    *   `ardupilot/ArduCopter/AP_MotorsTricopterVTOL.h`
    *   `ardupilot/ArduCopter/AP_MotorsTricopterVTOL.cpp`
2.  **Class Definition:** The new class, `AP_MotorsTricopterVTOL`, should inherit from `AP_Motors6DOF`.
3.  **Override Key Function:** The primary function to override is `output_armed_stabilizing()`. This function is called on every loop and is where we will inject our logic to write to the SBUS output array.
4.  **Initial Implementation:** The initial version of this function should simply pass through the standard 6DOF stabilization outputs to the first 6 SBUS channels to validate the basic data path.

### Step 2: Add a Master Feature Flag

To safely manage this custom code, a new, high-level feature flag must be added.

1.  **Create Custom Config Header:** If it doesn't exist, create a file like `ardupilAP_CustomConfig/AP_CustomConfig.h`.
2.  **Define Flag:** Add a new flag: `#define ENABLE_TRICOPTER_VTOL_BACKEND 1`.
3.  **Integrate Flag:** In the main `ArduCopter.cpp` (or equivalent vehicle-specific file where the motor mixer is initialized), use this flag to conditionally instantiate our new `AP_MotorsTricopterVTOL` class instead of the default mixer.

### Step 3: Implement State Broadcasting Logic

This is the core task. The `output_armed_stabilizing()` function in our new motor backend must be populated with the following logic:

1.  **Get QuadPlane State:** Get a reference to the `QuadPlane` object: `const QuadPlane &quadplane = AP::plane().quadplane;`.
2.  **Broadcast Transition Progress:**
    *   Get the raw transition value: `float mix_factor = quadplane.get_transition_mix();`.
    *   **Important:** This value is 1.0 for hover and fades to 0.0 for forward flight. Our design expects the opposite (0.0 for hover, 1.0 for FW). The value must be inverted: `float transition_progress = 1.0f - mix_factor;`.
    *   Scale this `transition_progress` (0.0-1.0) to a PWM value (1000-2000) and place it in the SBUS output array for `TRANSITION_PROGRESS_CHANNEL` (Channel 11).
3.  **Broadcast Plane Throttle:**
    *   Get the throttle command from the fixed-wing controller: `int16_t plane_throttle_scaled = SRV_Channels::get_output_scaled(SRV_Channel::k_throttle);`.
    *   Convert this to a standard PWM value and place it in the SBUS output array for `PLANE_THROTTLE_CHANNEL` (Channel 12).
4.  **Broadcast Pilot Commands & Stabilization:** The existing logic to pass through pilot commands (`Thrust`, `Forward`, `Lateral`) and the 6DOF stabilization outputs (`base_throttle`) should be maintained.

### Step 4: Implement Rear Motor Yaw Control

The rear motor requires special handling to provide yaw authority, as it does not tilt. The PFC's yaw stabilization output must be mixed into the rear motor's base throttle command.

1.  **Get Yaw Command:** Inside `output_armed_stabilizing()`, get the yaw stabilization command from the attitude controller. This is typically available as `motors->get_yaw()`, which provides a normalized value from -1.0 to 1.0.
2.  **Identify Rear Motor:** The 6DOF mixer will have a designated output for the rear motor (e.g., motor 5 or 6, depending on the frame configuration).
3.  **Mix Yaw into Throttle:**
    *   Take the base throttle for the rear motor as calculated by the 6DOF stabilization logic.
    *   Add or subtract the yaw command from this base throttle. A scaling factor may be required to achieve the desired yaw authority.
    *   `rear_motor_throttle = base_throttle_rear + (yaw_command * YAW_AUTHORITY_SCALE);`
4.  **Output:** Place this final, yaw-compensated throttle value onto the appropriate SBUS channel for the rear motor's SFC.

**Architectural Note:** This approach correctly keeps all stabilization logic (including yaw) within the PFC. The rear SFC will simply receive a fluctuating `base_throttle` command and will not need any special logic to handle yaw.

## 4.0 Final PFC SBUS Output Mapping (Summary)

This implementation will result in the PFC broadcasting the following complete state frame on SBUS Bus A:

| Channel | Signal Name | Source |
| :--- | :--- | :--- |
| **1-4** | `base_throttle[0-3]` | 6DOF Hover Controller (Front/Mid Motors) |
| **5-6** | `base_throttle[4-5]` | 6DOF Hover Controller + **Yaw Mix** (Rear Motors) |
| **7** | `hover_thrust_cmd` | Raw Pilot Input |
| **8** | `hover_forward_cmd` | Raw Pilot Input |
| **9** | `hover_lateral_cmd` | Raw Pilot Input |
| **11** | `transition_progress` | `QuadPlane` State Machine (Inverted) |
| **12** | `plane_throttle_cmd` | Fixed-Wing Controller |

This provides a clear and comprehensive plan for the next phase of development.
