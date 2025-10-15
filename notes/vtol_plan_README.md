# Design Document: 6DOF Tilt-Rotor VTOL Conversion (Final Architecture)

## 1.0 Objective

This document outlines the definitive strategy to convert the existing 6DOF vectored-thrust multi-copter into a full-capability, tilt-rotor VTOL QuadPlane. This plan is the result of an iterative design process and represents our final, agreed-upon architecture.

The core goal is to achieve a safe, smooth, and automated transition by creating a distributed control system where the PFC acts as a simple state broadcaster, the TVC manages all angle-related control, and the SFCs perform the final, state-aware blending of the different thrust models.

## 2.0 Core Architectural Principles

1.  **PFC is a "Dumb" State Broadcaster:** The ArduPilot PFC is not modified to understand our custom transition. It runs the standard `QuadPlane` logic. Our only change is a small, non-invasive addition to the `AP_Motors6DOF` backend to broadcast the raw, unmodified state of the `QuadPlane` state machine over SBUS. This ensures maximum decoupling and avoids a complex fork.
2.  **TVC is the "Blended Angle Controller":** The TVC is the sole authority on rotor angles. It is the only component with an IMU measuring the physical tilt. It reads the transition progress from the PFC and smoothly blends the *angle control commands* required for hover versus those required for forward flight. It broadcasts these blended angle commands, along with the raw hover thrust factor, within its existing 14-channel SBUS format.
3.  **SFCs are the "Smart Final Blenders":** The SFCs are the final link in the chain and the location of the critical thrust model blend. They receive state information from the PFC and blended angle commands from the TVC. They are responsible for blending the two different thrust sources (`pfc_base_throttle` vs. `plane_throttle`) and the two different thrust compensation models (`1/cos(angle)` vs. none) to calculate the final, absolute thrust for each of their motors.

## 3.0 Implementation Strategy

### 3.1 Part 1: PFC (ArduPilot) - The State Broadcaster

**Goal:** To broadcast the raw, unmodified state of the `QuadPlane` state machine over SBUS.

**File to Modify:** `ardupilot/ArduCopter/AP_Motors6DOF.cpp`

**Logic:** Inside `output_armed_stabilizing()`, add the following:

1.  **Get QuadPlane State:** Get a reference to the `QuadPlane` object: `const QuadPlane &quadplane = AP::plane().quadplane;`
2.  **Broadcast Transition Progress (SBUS Channel 11):**
    *   Get the raw transition mix factor: `float mix_factor = quadplane.get_transition_mix();` (This value is 1.0 for pure hover, and fades to 0.0 for pure forward flight).
    *   Convert this `mix_factor` (which we will treat as 0.0 for hover -> 1.0 for FW) to a PWM signal (1000µs -> 2000µs) and place it in the output array for SBUS Channel 11.
3.  **Broadcast Plane Throttle (SBUS Channel 12):**
    *   Get the throttle command from the fixed-wing controller: `int16_t plane_throttle_scaled = SRV_Channels::get_output_scaled(SRV_Channel::k_throttle);`
    *   Convert this to a standard PWM value and place it in the output array for SBUS Channel 12.
4.  **Existing Channels (1-9):** These continue to function as they do now, broadcasting the 6DOF stabilization outputs (`base_throttle`) and the raw pilot hover commands.

### 3.2 Part 2: TVC (The Brain) - The Blended Angle Controller

**Goal:** To blend the angle control laws for hover and forward flight and broadcast the result, plus the hover thrust factor, on its existing 14-channel SBUS frame.

**File to Modify:** `ardupilot/ArduCopter/custom_main.cpp` (and related files)

**Logic:**

1.  **Read State:** Read the `transition_progress` from the PFC.
2.  **Calculate Both Angle Control Models in Parallel:**
    *   **Hover Model:** Run existing logic to calculate the 12 per-pod `hover_vector` commands needed for hover stabilization.
    *   **Forward Flight Model:** Run new logic to calculate the 12 `fw_vector` commands needed to hold the 93-degree angle and provide roll/yaw stabilization in forward flight.
3.  **Blend the Vector Commands:** Perform a weighted average on each of the 12 vector commands using the `transition_progress` as the blend factor.
4.  **Calculate Hover Thrust Factor:** Calculate the `hover_thrust_factor` (`1/cos(current_physical_angle)`). This value is **not** blended.
5.  **Broadcast:** Send the final, blended control signals to the SFCs.
    *   **Ch 1-12:** The 12 `blended_vectors`.
    *   **Ch 13:** The raw, unblended `hover_thrust_factor`.
    *   **Ch 16:** Health channel.

### 3.3 Part 3: SFCs (The Muscle) - The Smart Final Blender

**Goal:** To receive data from both the PFC and TVC and perform the final blend of the two thrust models.

**File to Modify:** `led-drone-microcontrollers/caterpillar/motor-controller-unit/sfc_logic.cpp`

**Logic:**

1.  **Read All Inputs:**
    *   **From PFC Bus:** `pfc_base_throttle`, `transition_progress` (as `blend_factor`), `plane_throttle_cmd`.
    *   **From TVC Bus:** The `blended_vector_pitch` and `blended_vector_roll` for its pod, and the `hover_thrust_factor`.

2.  **Perform Two-Stage Blend of Inputs:**
    *   **Stage 1: Blend the Base Throttle Source:** Create the `final_base_throttle` by interpolating between `pfc_base_throttle` and `plane_throttle_cmd` using the `blend_factor`.
    *   **Stage 2: Blend the Thrust Compensation Model:** Create the `final_thrust_factor` by interpolating between the `hover_thrust_factor` and `1.0` (no compensation) using the `blend_factor`.

3.  **Perform Final, Continuous Mix:**
    *   Calculate `compensated_throttle = final_base_throttle * final_thrust_factor`.
    *   Apply the `blended_vector` differentials from the TVC to this `compensated_throttle` to get the final thrust for each of the 4 motors. This single mixing equation now works continuously across all flight phases.

4.  **Output:** Pass the final motor thrust values to the filtering and DShot output stage.

## 4.0 Confidence Assessment

*   **PFC Modifications (High Confidence):** This remains a minimal, non-invasive, and low-risk modification.
*   **TVC Architecture (High Confidence):** The role of the TVC as a "Blended Angle Controller" is now clearly defined, architecturally sound, and respects its unique sensor capabilities.
*   **SFC Architecture (High Confidence):** The role of the SFC as the "Final Blender" is now well-defined. It correctly centralizes the final mixing decision at the last possible point, using data from both master controllers. This is a robust and fault-tolerant design.
*   **Implementation Details (Medium Confidence):** The primary challenge remains the development and tuning of the new "Forward Flight" control laws (both for angle stabilization on the TVC and roll/yaw differentials). The blending curves will also require iterative tuning.
*   **System-Wide Tuning (Low Confidence):** This remains the area of highest uncertainty and will be the most time-consuming phase of the project, requiring methodical flight testing.
