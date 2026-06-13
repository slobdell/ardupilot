# Software Design Document: Tilt-Rotor VTOL Tricopter

**Version:** 1.0
**Status:** Implemented and Unit Tested

## 1.0 Objective & System Overview

This document details the software architecture for a servo-driven, tilt-rotor VTOL tricopter. This design is an evolution of a previous 24-motor multi-copter architecture, reusing its core PFC-TVC-SFC (Primary Flight Controller, Thrust Vectoring Controller, Secondary Flight Controller) distributed logic.

The primary goal is to achieve a safe, smooth, and automated transition between hover and forward flight by abstracting the control logic so that the same core components can be repurposed for this new airframe.

### 1.1 Physical Layout

The aircraft is a tricopter with two front motors that tilt for forward flight and one fixed rear motor.
- **Actuators:** Each of the two front motors is an independent unit, controlled by its own dedicated SFC. This unit consists of one motor for thrust and two servos for pitch and roll tilt, respectively. (In practice, the roll servo may be unused, but the abstraction supports it).
- **Control:** A single servo axis (pitch) is mechanically shared between the two front motor units, meaning they tilt in unison.

### 1.2 Decoupled Control Architecture

The system retains the decoupled three-controller hierarchy:
1.  **PFC (ArduPilot):** Acts as a high-level state manager. It runs a standard ArduPilot `QuadPlane` flight stack, providing stabilization in hover and fixed-wing control in forward flight. Its primary role in this custom architecture is to **broadcast the aircraft's state** to the other controllers.
2.  **TVC ("The Brain"):** The sole authority on **rotor tilt angles**. It reads the desired state from the PFC and pilot commands, runs the necessary PID loops to calculate the correct tilt angle, and broadcasts these commands to the SFCs.
3.  **SFCs ("The Muscle"):** The final link in the chain, responsible for **actuation**. Each SFC listens to both the PFC and TVC and performs the final, state-aware blending of commands to drive its motor and servos.

---

## 2.0 End-to-End Control Flow

The system achieves smooth transition by having the SFCs perform a "two-stage blend" based on the `transition_progress` state broadcast by the PFC.

### 2.1 PFC (State Broadcaster)

The PFC runs an unmodified `QuadPlane` state machine. A small, non-invasive hook in the motor mixer broadcasts the following key state variables over SBUS Bus A:
- **`base_throttle[0-5]`:** Per-motor stabilization thrust from the hover attitude controller (e.g., Copter's PID loops). The front left SFC subscribes to motor 1, the front right to motor 2, etc.
- **`transition_progress`:** The current state of the VTOL transition (0.0 = pure hover, 1.0 = pure forward flight).
- **`plane_throttle_cmd`:** The throttle command from the fixed-wing attitude controller.

### 2.2 TVC (Angle Controller)

The TVC is responsible for calculating the final, blended servo angles.
1.  **State Reading:** Reads `transition_progress` from the PFC.
2.  **Parallel Model Calculation:** It calculates two separate control models simultaneously:
    *   **Hover Model:** Reads pilot's desired `forward` and `lateral` commands and uses its onboard IMU and cascaded PID loops to calculate the precise `vector_pitch_out` and `vector_roll_out` needed to achieve the desired movement in hover.
    *   **Forward-Flight Model:** Commands a fixed, predetermined forward tilt angle (e.g., 90 degrees, represented as `1.0f`).
3.  **Angle Blending:** It performs a linear interpolation between the `hover_model_pitch/roll_output` and the `fw_model_pitch/roll_output` using `transition_progress` as the blend factor.
4.  **Thrust Factor Calculation:** It calculates the raw `hover_thrust_factor` (`1.0 / cos(angle)`) needed to compensate for thrust vectoring in hover. This value is **not** blended.
5.  **Broadcast:** The TVC broadcasts the final commands on SBUS Bus B.

#### 2.2.1 Key Control Strategies
The TVC employs several sophisticated strategies to ensure stable and responsive control:
- **Cascaded PID Control:** The controller uses a cascaded structure. An outer "angle" PID loop calculates a target angular rate based on the pilot's desired angle. An inner "rate" PID loop then works to achieve that rate, providing smooth and precise control.
- **Gain Scheduling:** The gains for the inner rate PID loops are not static. They are dynamically and linearly interpolated based on the magnitude of the pilot's 3D command vector. This makes the controller highly responsive at low thrust and stable and smooth at high thrust.
- **Input Shaping (Altitude Priority):** The TVC prioritizes altitude control by budgeting thrust. It calculates the maximum available thrust for horizontal movement after accounting for the vertical component. If the pilot's combined command exceeds 100% total thrust, the horizontal commands (`forward`/`lateral`) are scaled back to prevent altitude loss during aggressive maneuvers.
    *   **Channels 1-2 (or 1-12):** The final `blended_vector_pitch` and `blended_vector_roll`.
    *   **Channel 13:** The raw, unblended `hover_thrust_factor`.

### 2.3 SFC (Final Mixer & Actuator)

The SFC is where the two control models (hover and forward flight) are seamlessly blended into final motor and servo commands.
1.  **Read All Inputs:** It reads state from the PFC (Bus A) and angle commands from the TVC (Bus B).
2.  **Perform Two-Stage Blend:**
    *   **Stage 1: Blend the Throttle Source.** It creates a `final_base_throttle` by interpolating between the PFC's `base_throttle` (for hover) and the PFC's `plane_throttle_cmd` (for forward flight), using `transition_progress` as the blend factor.
    *   **Stage 2: Blend the Thrust Compensation Model.** It creates a `final_thrust_factor` by interpolating between the `hover_thrust_factor` (from the TVC) and `1.0` (no compensation needed in forward flight), using `transition_progress` as the blend factor.
3.  **Final Calculation:**
    *   It calculates the `final_compensated_throttle = final_base_throttle * final_thrust_factor`.
4.  **Output:**
    *   The `final_compensated_throttle` is sent to the motor via the `thrust_to_dshot()` function.
    *   The `blended_vector_pitch` and `blended_vector_roll` (from the TVC) are sent directly to the servos via the `float_to_servo_pwm()` function.

#### 2.3.1 Key Output Processing & Safety Features
Before sending commands to the actuators, the SFC performs several critical steps:
- **Pre-Flight Gatekeeper:** The SFC will not send any command to the motors until it receives a continuous "healthy" signal from the TVC on a dedicated SBUS channel. This prevents motor spin-up if the TVC is not ready.
- **Thrust Curve Linearization:** The final motor command is passed through the `thrust_to_dshot()` function. This applies a non-linear curve to the command, compensating for the non-linear thrust response of propellers, which ensures that a 50% command results in approximately 50% thrust.
- **Low-Pass Filtering:** The final linear thrust value for the motor is passed through a low-pass filter to smooth the signal, reducing electrical noise and improving motor efficiency and longevity.
- **Hardware-Accelerated Servo Control:** Servo outputs are driven using the ESP32's built-in `ledc` (LED Control) peripheral via the `ServoPWM` driver. This utilizes dedicated hardware timers for precise and efficient PWM generation, minimizing CPU overhead.

This architecture ensures a single, continuous mixing equation that is valid across all phases of flight, from hover to transition to forward flight.

---

## 3.0 Key Abstractions & Recent Changes

### 3.1 `use_per_pod_scaling` Abstraction

A key insight during development was that the `VTOL_MODE` flag was breaking the control abstraction. The output format (global vs. per-pod vector commands) should be independent of the flight mode.

The logic has been refactored so that the `use_per_pod_scaling` flag is the sole determinant of the SBUS channel routing for vector commands, in both multicopter and VTOL modes.
- If `true`, the TVC broadcasts unique pitch/roll commands for each SFC on channels `sfc_id*2` and `sfc_id*2+1`.
- If `false` (as is the case for this tricopter design), the TVC broadcasts one global pitch/roll command, and all SFCs listen to those global channels.

This ensures the SFC firmware is generic and reusable across different physical airframes without modification.

### 3.2 Saturation Logic for Servos

The original saturation logic in the TVC was designed for differential thrust, where it would clip vector commands based on the available motor headroom. This is incorrect for a servo-driven system.

The logic has been updated:
- When `VTOL_MODE` is true, the TVC's saturation logic is bypassed.
- Instead, the PID output for the vector commands is simply constrained to the valid normalized servo range (`-1.0f` to `1.0f`).
- The `saturated` flag is now set if the PID controller *requests* an output beyond this range. This provides correct anti-windup feedback to the PID integrator while respecting the physical limits of the servos.

### 3.3 Dynamic Thrust Factor Calculation

All hardcoded "magic numbers" for the thrust factor (e.g., `1.5f`, `2.0f`) have been removed from both the TVC and SFC codebases. A `MAX_ANGLE_DEG` constant is now defined in both projects, and a `MAX_THRUST_FACTOR` is calculated from it (`1.0 / cos(angle)`). All logic now uses this dynamic constant, ensuring that any future changes to the maximum tilt angle are automatically and safely reflected in the thrust compensation calculations.
