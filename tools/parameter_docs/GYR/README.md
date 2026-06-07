# Gyroscope Configuration (GYR)

## Overview
The **GYR** parameter group (often appearing as `INS_GYR_` in the full parameter list) handles the low-level settings for the **Gyroscopes** (Angular Rate Sensors).

Gyros are the most critical sensors for flight. They measure the vehicle's rotation rate and are the primary input for the high-frequency attitude control loops.

## Key Concepts

### 1. Gyro Calibration (`GYR_CAL`)
Toggles the automatic gyro calibration at boot.
*   **Recommendation:** Keep enabled. The autopilot measures the sensor drift while the vehicle is stationary on the ground and subtracts it.

### 2. Sensor Identification (`GYR_ID`)
Unique hardware identifier for the gyroscope chip, allowing the system to track specific calibrations and health across reboots.

## Parameter Breakdown

*   **`GYR_ID`**: Unique hardware ID.
*   **`GYR_CAL`**: Calibration trigger/state.

## Integration Guide
*   **Startup:** **DO NOT MOVE** the vehicle while it is booting up. The "Gyro Calibration" occurs during the first few seconds of power-on. Movement during this phase will result in "Bad Gyro Health" or an uncommanded drift in flight.

## Developer Notes
*   **Library:** `libraries/AP_InertialSensor`.
*   **Redundancy:** Most boards have 2 or 3 gyros; the `INS_` library handles the voting and health monitoring between them.