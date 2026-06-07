# Raw Data Configuration (RAW)

## Overview
The **RAW** parameter group (specifically `RAW_DATA` and `RAW_LOG_OPT`) configures the recording of unfiltered, low-level sensor information.

## Key Concepts

### 1. GPS Raw Logging (`RAW_DATA`)
Normally, ArduPilot only logs the calculated Lat/Lon position. Enabling `RAW_DATA` tells the GPS driver to log the raw satellite measurements (pseudoranges).
*   **Purpose:** Required for **PPK** (Post-Processed Kinematics) mapping applications.

### 2. IMU Raw Logging (`RAW_LOG_OPT`)
Allows for logging raw IMU samples at very high frequencies (e.g., the full 1kHz or 8kHz rate).
*   **Purpose:** Used for high-fidelity vibration analysis and tuning the dynamic harmonic notch filters.

## Developer Notes
*   **Library:** `libraries/AP_GPS`, `libraries/AP_InertialSensor`.
*   **Performance:** Enabling raw logging drastically increases the log file size and CPU load. Use only when troubleshooting or performing mapping missions.