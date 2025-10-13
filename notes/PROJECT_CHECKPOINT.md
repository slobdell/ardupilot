# Project Checkpoint: SBUS and Logging Validation

This document outlines the validated hardware and software configuration at this stage of the project. The primary goals of this checkpoint have been achieved: end-to-end SBUS communication has been verified, and a reliable logging system is in place.

## 1. Feature Summary

- **SBUS Input:** **Validated.** The flight controller can successfully read and parse SBUS data from an external source.
- **SBUS Output:** **Validated.** The flight controller can successfully generate and transmit valid SBUS data.
- **Custom Logging:** **Validated.** A dedicated UART port is configured for printing custom, human-readable debug messages.

## 2. UART Port Assignments

The following serial ports on the MicoAir H743 have been configured and validated for these specific roles:

- **UART1 (`SERIAL1`): SBUS Output**
  - This port is configured to send SBUS frames. It is used for commanding external devices like servos or other microcontrollers.
  - ArduPilot Parameter: `SERIAL1_PROTOCOL = 30` (SBUS Output)

- **UART4 (`SERIAL4`): Custom Logging Port**
  - This port is used exclusively for printing debug messages from the custom `newMain()` loop. It is configured at 115200 baud.
  - The firmware contains a runtime hack to force this port's protocol to "Scripting" (`SERIAL4_PROTOCOL = 19`) to ensure it is always initialized for logging, regardless of saved parameters.

- **UART6 (`SERIAL5`): SBUS Input (RC Input)**
  - This is the primary RC Input port for the flight controller. It is configured to receive SBUS frames.
  - ArduPilot Parameter: `SERIAL5_PROTOCOL = 23` (RC Input)

## 3. Validation Method: Hardware Loopback

A hardware-in-the-loop (HITL) test was performed to validate SBUS functionality without relying on a traditional RC transmitter or receiver.

### 3.1. Test Rig

- **SBUS Writer:** An ESP32S3 microcontroller was programmed to act as a synthetic RC transmitter, generating a continuous stream of static SBUS frames. This was connected to the flight controller's SBUS Input (UART6).
- **SBUS Reader:** A second ESP32S3 microcontroller was programmed to act as an SBUS signal validator. It reads, parses, and prints incoming SBUS frames to its own serial console. This was connected to the flight controller's SBUS Output (UART1).

### 3.2. Test Procedure

1.  **Input Validation:** The SBUS Writer sent known raw SBUS values. The flight controller's custom logging on UART4 was monitored to confirm that it was reading and correctly scaling these raw values into the expected PWM microsecond values.
2.  **Output Validation:** The flight controller's `exampleOutput()` function was used to send known PWM microsecond values to the SBUS Output port. The SBUS Reader's serial log was monitored to confirm that it was receiving and correctly parsing the corresponding raw SBUS values.

This closed-loop test successfully validated the entire SBUS data path and confirmed the scaling formulas used by ArduPilot.

---

# Project Checkpoint: TVC Logic Integration

This section summarizes the successful porting of the Thrust Vectoring Controller (TVC) logic into the main ArduPilot custom firmware. The primary goal of this checkpoint—to replicate the behavior of the standalone TVC prototype within the ArduPilot ecosystem—has been accomplished at the code level.

## 4. Feature Summary

- **TVC Logic Ported:** The core control logic from the Gemini-generated `thrust-vector-controller.ino` project has been fully integrated into the `custom_main.cpp` file.
- **Custom Libraries Integrated:** The validated, standalone `PID` and `filters` libraries have been successfully added to the ArduCopter build, ensuring the control algorithms are identical to the prototype.
- **ArduPilot HAL Integration:** All hardware-specific code from the prototype has been replaced with robust ArduPilot HAL equivalents. This includes:
    - **State Estimation:** Raw IMU reading and Madgwick filtering have been replaced by direct calls to ArduPilot's EKF, using `AP::vehicle()->get_osd_roll_pitch_rad()` for attitude and `copter.attitude_control->get_latest_gyro()` for filtered angular rates.
    - **Input/Output:** Standalone SBUS libraries have been replaced with the standard `RC_Channels` and `SRV_Channels` APIs for reading pilot commands and writing vectoring commands.
- **Advanced Control Strategy Implemented:** A sophisticated "Per-Pod Output Scaling" feature has been implemented to address the problem of differing motor authority. This logic is controlled by a `PER_POD_SCALING` feature flag.

## 5. Current State: Validated Logic (Untested)

This checkpoint represents a "code complete" status for the TVC integration. The logic is believed to be a sound and faithful implementation of the design, but it has **not yet been validated through compilation or hardware testing.**

### 5.1. Core Logic (Believed Valid)

- The cascaded PID control structure, gain scheduling based on global command magnitude, and thrust compensation factor calculation have been ported line-for-line.
- The failsafe logic and motor-off detection have been adapted to use ArduPilot's `rc().in_rc_failsafe()` and PWM-based thresholds.

### 5.2. Per-Pod Scaling Feature (Believed Valid)

- When `PER_POD_SCALING` is `true`, the code correctly calculates the average `base_throttle` across all pods.
- It then computes a unique scale factor for each pod (`average_throttle / pod_throttle`) to determine how much of the global vectoring command to apply.
- It correctly formats and sends a 13-channel SBUS output frame containing the 12 unique scaled vector commands and the 1 global thrust factor.
- When the flag is `false`, the code reverts to the original, simpler logic of broadcasting 3 global channels.

### 5.3. Next Steps

The immediate next step is to compile the firmware and resolve any remaining build errors. Following a successful compilation, a comprehensive bench test is required to validate the following:
- Correct reading of all RC input channels.
- Correct calculation and output of the 13-channel SBUS data stream.
- Correct response of the PID controllers and gain scheduling logic to simulated inputs.
- Correct behavior of the `PER_POD_SCALING` feature flag.