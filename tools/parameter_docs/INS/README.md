# Inertial Navigation System (INS)

## Overview
The **INS** parameter group is the core configuration for the **Inertial Sensors** (Accelerometers and Gyroscopes). This library is responsible for sampling raw sensor data, applying calibrations, and filtering the results before they are consumed by the EKF (State Estimator) and PID controllers.

This is the most critical system for flight stability. If the INS data is noisy or incorrectly calibrated, the vehicle cannot fly.

## Key Concepts

### 1. Calibration (Offsets & Scaling)
Every IMU has manufacturing imperfections (e.g., when the drone is still, the accel might read 0.05m/s² instead of 0).
*   **Offsets (`_OFFS`):** Shift the zero point.
*   **Scaling (`_SCAL`):** Ensures that 1G of gravity actually measures as 9.81m/s².

### 2. Harmonic Notch Filters (`INS_HNTCH_...`)
This is a modern ArduPilot feature that uses a high-Q notch filter to "erase" motor vibration noise.
*   **Dynamic Tracking:** The filter can follow the motor RPM in real-time (via ESC telemetry or throttle) to target the exact frequency of the propeller noise.
*   **Result:** Allows for much higher PID gains and a "locked-in" flight feel.

### 3. Temperature Calibration (`INS_TCAL_...`)
MEMS sensors drift as they heat up. The `TCAL` system applies complex polynomial curves to counteract this drift, ensuring a stable horizon from a cold boot to a hot flight.

### 4. Fast Sampling (`INS_FAST_SAMPLE`)
Enables pulling data from sensors at 8kHz or 16kHz for better aliasing rejection.

## Parameter Breakdown

*   **`INS_ACC_FILTER`**: Low-pass filter for accelerometers (Hz).
*   **`INS_GYRO_FILTER`**: Low-pass filter for gyroscopes (Hz).
*   **`INS_ENABLE_MASK`**: Selects active IMUs.
*   **`INS_HNTCH_ENABLE`**: Toggles the harmonic notch.

## Integration Guide

### Accelerometer Calibration
1.  **Level:** Place vehicle on a perfectly level surface. Click "Calibrate Level."
2.  **6-Point:** Follow the GCS prompts to place the vehicle on each of its 6 sides. This populates the `INS_ACCn_OFFS` and `INS_ACCn_SCAL` values.

### Tuning the Notch Filter
1.  **Log:** Fly and record raw IMU data (`INS_LOG_BAT_MASK = 1`).
2.  **Analyze:** Use the Mission Planner "FFT" tool to find the noise peak (e.g., 180Hz).
3.  **Config:** Set `INS_HNTCH_FREQ` to 180 and `INS_HNTCH_BW` to 90.

## Developer Notes
*   **Library:** `libraries/AP_InertialSensor`.
*   **Criticality:** High. The `INS` loop runs at the highest priority in the firmware.