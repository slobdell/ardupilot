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
