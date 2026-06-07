# IMU General Configuration (IMU)

## Overview
The **IMU** parameter group (often appearing as `INS_` in the full parameter list) configures the global behavior of the **Inertial Measurement Units**.

This group handles physical offsets and timing constants that apply to all internal sensors.

## Key Concepts

### 1. Lever-Arm Compensation (`IMU_POS_X/Y/Z`)
Defines the distance (in meters) from the center of gravity (CG) of the vehicle to the physical location of the IMU chip on the circuit board.
*   **Importance:** If the IMU is far from the CG (e.g., on the tail of a long drone), the centripetal acceleration during a turn will bias the EKF. Setting these offsets allows the math to "shift" the measurement back to the CG.

### 2. Sample Rate (`IMU_SAMPLE_RATE`)
Defines the internal frequency (Hz) at which raw sensor data is pulled from the IMU hardware.
*   **Standard:** 1000Hz (1kHz).
*   **High-End:** 2000Hz or 4000Hz (reduces aliasing on high-vibration frames).

## Parameter Breakdown

*   **`IMU_POS_X/Y/Z`**: Physical offset from CG (meters).
*   **`IMU_SAMPLE_RATE`**: Internal hardware sampling frequency.

## Developer Notes
*   **Library:** `libraries/AP_InertialSensor`.
*   **Alias:** In most firmwares, these are mapped to `INS_POS_...` and `INS_GYRO_RATE`.