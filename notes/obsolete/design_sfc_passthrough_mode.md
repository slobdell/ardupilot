# SFC Passthrough Mode

**Status:** Implemented & Validated

## 1. Overview & Intent

This document describes the `SFC_MODE_PASSTHROUGH` feature within the Secondary Flight Controller (SFC) firmware.

### 1.1. Architectural Context

The flight control system is composed of three main units:
- **PFC (Primary Flight Controller):** An ArduPilot-based unit responsible for high-level state estimation and flight control.
- **TVC (Thrust Vector Controller):** The "brain" of the system, responsible for complex calculations for VTOL configurations.
- **SFC (Secondary Flight Controller):** The "muscle" of the system. Multiple SFC units are used to drive actuators (motors and servos).

The SFC firmware is designed to be highly reusable and is configured at runtime to operate in one of several modes.

### 1.2. Purpose of Pass-Through Mode

While `SFC_MODE_MULTICOPTER` and `SFC_MODE_VTOL` handle complex, state-aware mixing, some actuator setups do not require this complexity.

`SFC_MODE_PASSTHROUGH` provides a generic, configurable way to directly map SBUS input channels from the PFC to physical actuator outputs on an SFC. This allows the SFC to act as a simple "SBUS-to-Actuator" converter, while still benefiting from the SFC's core features like signal filtering and safety checks.

A primary use case is the **VTOL Tricopter's rear yaw assembly**, which consists of two fixed motors and one yaw servo. The PFC can handle the tricopter mixing and output a single "rear thrust" command and a "yaw servo" command. A dedicated SFC in pass-through mode can then take these simple inputs and drive the three physical actuators.

## 2. Technical Implementation

### 2.1. Configuration (`SFC_Config` struct)

An SFC unit is configured for this mode by setting the following fields in its `SFC_Config` object:

- **`.mode`**: Must be set to `SFC_MODE_PASSTHROUGH`.
- **`.actuator_types`**: An array defining whether each of the 4 actuator pins is an `ACTUATOR_MOTOR`, `ACTUATOR_SERVO`, or `ACTUATOR_UNUSED`.
- **`.passthrough_config`**: A dedicated struct with the following members:
    - **`mappings`**: An array of `Passthrough_Mapping` structs. Each struct contains:
        - `sbus_input_channel`: The index (0-15) of the SBUS channel to read from the PFC.
        - `actuator_output_index`: The index (0-3) of the physical actuator pin to write to.
    - **`num_mappings`**: The number of valid entries in the `mappings` array.

A key feature of this implementation is support for a **one-to-many** relationship. Multiple entries in the `mappings` array can point to the *same* `sbus_input_channel` but different `actuator_output_index` values. This is essential for driving multiple physical motors from a single conceptual motor command from the PFC.

### 2.2. Arming Safety Check (Inferred Arming)

A critical safety feature of this mode is that the SFC will not send throttle commands to motors unless it can infer that the PFC (ArduPilot) is armed. Servos are allowed to move while disarmed.

- **Mechanism:** The armed state is inferred by monitoring a configurable list of SBUS channels that correspond to the PFC's main motor outputs. If any of these channels has a value above a defined threshold, the PFC is considered armed.
- **Configuration:** The `passthrough_config` struct contains the following fields for this check:
    - `pfc_motor_sbus_channels`: An array of SBUS channel indices (0-15) that the SFC monitors.
    - `num_pfc_motor_channels`: The number of channels in the monitoring list.
    - `arming_threshold_sbus`: The raw SBUS value (e.g., 1100) above which a monitored motor channel is considered "spinning."
- **Logic:**
    1. Before processing any mappings, the logic iterates through the `pfc_motor_sbus_channels` list.
    2. If any channel's value is greater than `arming_threshold_sbus`, a boolean flag `is_pfc_armed` is set to `true`.
    3. When processing the actuator mappings, if the target actuator is a motor (`ACTUATOR_MOTOR`), its output command is forced to `0` unless the `is_pfc_armed` flag is `true`.

### 2.3. Signal Processing and Output

All actuator outputs are filtered and rate-limited for smooth and safe operation.

- **SBUS Conversion:**
    - For actuators of type `ACTUATOR_MOTOR`, the mapped SBUS value is converted to a float from `0.0` to `1.0`.
    - For actuators of type `ACTUATOR_SERVO`, the mapped SBUS value is converted to a float from `-1.0` to `1.0`.
- **Low-Pass Filtering:** The resulting float command for *every* actuator (both motor and servo) is passed through a dedicated low-pass filter.
- **Servo Output Rate:** The final PWM command sent to servos is rate-limited to a configurable frequency, with the filter cutoff automatically derived to satisfy the Nyquist theorem.

## 3. Validation

The passthrough mode has been fully validated through a comprehensive suite of unit tests. These tests confirm:
- Correct mapping of single inputs to single outputs.
- Correct mapping of one input to many outputs.
- The inferred arming check correctly prevents motors from spinning when the PFC is disarmed.
- The arming check's edge case (an empty monitoring list) correctly and safely results in motors never arming.
- Servos operate correctly regardless of the PFC's armed state.
- Unused actuators remain inactive.

## 4. Example Implementation: VTOL Tricopter Rear Pod

- **Hardware:** 1 SFC unit, 2 physical motors, 1 physical yaw servo.
- **PFC Outputs (Example):**
    - SBUS Ch 3 (index 2): "Rear Motor Thrust"
    - SBUS Ch 4 (index 3): "Yaw Servo Command"
    - SBUS Ch 5-7 (indices 4-6): PFC's main multicopter motor outputs (for arming check).
- **SFC Configuration (`passthrough_sfc_config`):**
  ```c++
  SFC_Config passthrough_sfc_config = {
      .mode = SFC_MODE_PASSTHROUGH,
      .actuator_types = {
          ACTUATOR_MOTOR,   // Output 0: Left Rear Motor
          ACTUATOR_MOTOR,   // Output 1: Right Rear Motor
          ACTUATOR_SERVO,   // Output 2: Yaw Servo
          ACTUATOR_UNUSED
      },
      .passthrough_config = {
          .mappings = {
              // Map PFC "Rear Thrust" to BOTH physical motors
              { .sbus_input_channel = 2, .actuator_output_index = 0 },
              { .sbus_input_channel = 2, .actuator_output_index = 1 },
              // Map PFC "Yaw Servo" to the physical servo
              { .sbus_input_channel = 3, .actuator_output_index = 2 }
          },
          .num_mappings = 3,

          // Configure arming check to monitor PFC's 3 main motors
          .pfc_motor_sbus_channels = {4, 5, 6},
          .num_pfc_motor_channels = 3,
          .arming_threshold_sbus = 1100
      }
  };
  ```