# Accelerometer Configuration (ACC)

## Overview
The **ACC** parameter group contains configuration settings for the **Accelerometers** within the Inertial Measurement Units (IMUs). These parameters manage the low-level identification, alignment, and calibration offsets of the physical sensors.

In ArduPilot, accelerometers are the primary source for the "Gravity Vector," which establishes the vehicle's "Down" reference (Level Horizon). They are also integrated to estimate velocity and position (INS).

## Key Concepts

### 1. Sensor Identification (`ACC_ID`)
Every accelerometer detected on the hardware bus (SPI, I2C, DroneCAN) is assigned a unique ID. This ID allows the autopilot to track the health and calibration status of a specific physical sensor even if the board is rebooted or if the sensor order changes.

### 2. Body Frame Alignment (`ACC_BODYFIX`)
The autopilot needs to know which sensor is "perfectly aligned" with the flight controller board. This sensor becomes the reference for the "Body Frame." If the board itself is mounted at an angle (see `AHRS_ORIENTATION`), the `ACC_BODYFIX` sensor rotates with the board, while the mathematical solution is rotated to match the vehicle frame.

### 3. Temperature Calibration (`ACC_CALTEMP`)
MEMS sensors drift with temperature. During factory or user calibration, the temperature is recorded (`ACC_CALTEMP`). This reference allows the `TCAL` (Temperature Calibration) system to apply compensation curves effectively.

## Parameter Breakdown

*   **`ACC_ID`**: Unique hardware identifier for the sensor.
*   **`ACC_BODYFIX`**: Selects the primary "Body Fixed" accelerometer (usually IMU 1 or 2).
*   **`ACC_CALTEMP`**: The temperature (°C) measured during the 6-point accelerometer calibration.
*   **`ACC_TRIM`**: (SITL Only) Used for simulating sensor installation errors.

## Integration Guide

### Calibration
These parameters are typically set automatically during the **Accelerometer Calibration** process:
1.  **Level Horizon:** Sets the AHRS trim.
2.  **6-Point Calibration:** Rotates the vehicle through all 6 axes to determine offsets and scaling factors. This populates `ACC_CALTEMP` and the internal `INS_ACCn_OFFS` / `INS_ACCn_SCAL` parameters (often visible in the `INS` group, not `ACC`).

### Troubleshooting
*   **"Inconsistent Accelerometers":** If you see this pre-arm failure, it means the vector length or alignment of the secondary accelerometers disagrees with the primary (`ACC_BODYFIX`). Recalibrate.
*   **Drifting Horizon:** If the horizon drifts during flight, check for high vibrations (Vibe Logging) or poor temperature calibration.

## Developer Notes
*   **Library:** `libraries/AP_InertialSensor`
*   **Key Class:** `AP_InertialSensor`
*   **Legacy Note:** In newer ArduPilot versions, many raw sensor parameters are grouped under `INS_` (Inertial Navigation System). The `ACC_` group often persists for legacy compatibility or specific `AP_Periph` configurations.