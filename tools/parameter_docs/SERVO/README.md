# Servo Output Configuration (SERVO)

## Overview
The **SERVO** parameter group (often appearing as `SERVOx_` or `MOT_`) configures the physical **PWM / DShot / SBus** outputs of the flight controller.

While `RCMAP` handles *Input*, the `SERVO` group handles *Output*. It defines what each pin on the servo rail actually does (e.g., Motor 1, Aileron, Camera Trigger, etc.) and how the signal is scaled.

## Key Concepts

### 1. Servo Functions (`SERVOx_FUNCTION`)
**The most important setting.** Tells the autopilot what is plugged into the pin.
*   **0:** Disabled.
*   **33:** Motor 1 (Multicopter).
*   **4:** Aileron (Plane).
*   **10:** Camera Trigger.
*   **51:** RC Passthrough (Directly copies an input channel to this output).

### 2. Output Calibration (`SERVOx_MIN`, `MAX`, `TRIM`)
Defines the pulse-width limits (microseconds).
*   **`MIN`**: The "Low" endpoint (typically 1100us).
*   **`MAX`**: The "High" endpoint (typically 1900us).
*   **`TRIM`**: The "Neutral" position (typically 1500us).
*   **`REVERSED`**: Flips the direction of travel (0=Normal, 1=Reversed).

### 3. BLHeli / DShot Pass-through (`SERVO_BLH_...`)
Configures the interface for BLHeli_32 ESCs, allowing the autopilot to perform firmware updates and read RPM telemetry (Bi-directional DShot).

## Parameter Breakdown

*   **`SERVO_RATE`**: The update frequency for standard PWM servos (default 50Hz).
*   **`SERVO_DSHOT_RATE`**: The speed of digital DShot outputs.
*   **`SERVO_GPIO_MASK`**: Converts PWM pins into simple digital High/Low pins.

## Integration Guide

### Setting up a New Motor
1.  Connect ESC to Output 1.
2.  Set `SERVO1_FUNCTION = 33` (Motor 1).
3.  Set `MOT_PWM_TYPE` to your desired protocol (e.g., DShot600).
4.  **Test:** Use the "Motor Test" tab in the GCS to verify rotation direction. If wrong, use `SERVO1_REVERSED` (for PWM) or BLHeliSuite (for DShot).

## Developer Notes
*   **Library:** `libraries/SRV_Channel`.
*   **Safety:** PWM outputs are disabled until the vehicle is Armed or the Hardware Safety Switch is pressed.