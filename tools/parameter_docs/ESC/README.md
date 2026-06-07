# ESC Telemetry & Calibration (ESC)

## Overview
The **ESC** parameter group (primarily within **AP_Periph** firmware) configures the communication with Electronic Speed Controllers (ESCs) for the purpose of telemetry and calibration.

While the main autopilot handles motor *control* (via PWM or DShot), a DroneCAN node (or the autopilot itself) can listen to the ESC's serial telemetry stream to report RPM, Temperature, Voltage, and Current for each individual motor.

## Key Concepts

### 1. ESC Telemetry
Many modern ESCs (BLHeli_32, APD, KISS) output a low-speed serial stream (typically 115200 baud) containing real-time health data.
*   **`ESC_TELEM_PORT`**: Selects the UART used to listen to the ESCs.
*   **`ESC_TELEM_RATE`**: Frequency (Hz) at which this data is forwarded to the main autopilot via CAN or MAVLink.

### 2. ESC Calibration (`ESC_CALIBRATION`)
This parameter (in some firmwares) can trigger a passthrough mode to allow a PC-based configurator (like BLHeliSuite) to talk through the autopilot to the ESCs for firmware updates and tuning.

## Parameter Breakdown

*   **`ESC_TELEM_PORT`**: Serial port index for ESC data.
*   **`ESC_PWM_TYPE`**: (AP_Periph) Defines the output protocol to the ESC (PWM, OneShot, DShot).
*   **`ESC_RATE`**: The update rate of the motor control signal (Hz).

## Integration Guide
1.  **Hardware:** Connect the "TLM" pin from all ESCs together (usually) and wire to the RX pin of the designated `ESC_TELEM_PORT`.
2.  **Enable:** Set the port and rate.
3.  **Verify:** Check the `ESC_TELEMETRY` or `ESC` messages in the DataFlash log.

## Developer Notes
*   **Library:** `Tools/AP_Periph` and `libraries/AP_ESC_Telem`.
*   **Advanced:** Highly integrated with the **Harmonic Notch Filter** (`INS_HNTCH_`), which uses individual motor RPM to dynamically target vibration frequencies.