# Torqeedo Motor Interface (TRQD)

## Overview
The **TRQD** parameter group configures the driver for **Torqeedo Electric Boat Motors**.

Torqeedo is a leading manufacturer of electric outboards for boats. ArduPilot can communicate with these motors via a serial link (RS485) to read battery level, power consumption, and to provide precise throttle control.

## Key Concepts

### 1. Communication Type (`TRQD_TYPE`)
Defines how the autopilot talks to the motor.
*   **0:** Disabled.
*   **1:** Serial (RS485).

### 2. Output Scaling (`TRQD_POWER`)
Sets the maximum power limit for the motor, allowing the pilot to cap the speed for trolling or to extend battery life.

## Parameter Breakdown

*   **`TRQD_TYPE`**: Driver selection.
*   **`TRQD_DE_PIN`**: (RS485) Data Enable pin for the UART adapter.
*   **`TRQD_SLEW_TIME`**: Limits how fast the motor power can ramp up/down.

## Integration Guide
1.  **Hardware:** Requires a UART-to-RS485 adapter. Connect the adapter to an autopilot UART and the motor's diagnostic port.
2.  **Config:** Set `TRQD_TYPE = 1` and `SERIALx_PROTOCOL = 41` (Torqeedo).

## Developer Notes
*   **Library:** `libraries/AP_Torqeedo`.
*   **Context:** Only used in **ArduRover** (Boats).