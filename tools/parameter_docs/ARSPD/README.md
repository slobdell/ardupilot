# Airspeed Sensor Configuration (ARSPD)

## Overview
The **ARSPD** parameter group configures the hardware interface and signal processing for **Airspeed Sensors** (Pitot Tubes). ArduPilot supports multiple redundant airspeed sensors (`ARSPD`, `ARSPD2`, etc.).

Accurate airspeed data is vital for:
1.  **Energy Management:** Efficient climbing and cruising (TECS).
2.  **Stall Prevention:** Flying at optimal angle of attack.
3.  **Wind Estimation:** Calculating wind speed and direction by comparing Airspeed vector vs. Ground Speed (GPS) vector.

## Key Concepts

### 1. Sensor Selection (`ARSPD_TYPE`)
Tells the driver which sensor hardware is connected.
*   **1 (Analog):** Older MPXV7002DP sensors connected to an ADC pin.
*   **2 (I2C - MS4525):** The standard digital sensor for Pixhawk (MS4525DO).
*   **3 (I2C - MS5525):** Higher resolution digital sensor.
*   **6 (I2C - SDP3x):** Sensirion SDP3x (very high sensitivity, requires 0 calibration).
*   **8 (DroneCAN):** UAVCAN/DroneCAN sensors.

### 2. Calibration (`ARSPD_RATIO` / `ARSPD_AUTOCAL`)
*   **Ratio:** Adjusts the scaling between pressure (Pa) and speed (m/s) to account for pitot tube placement errors (position error).
*   **Autocal:** If enabled, the autopilot automatically adjusts the Ratio during flight by comparing GPS ground speed and Airspeed during loiter turns.

### 3. Tube Order (`ARSPD_TUBE_ORDR`)
Digital differential pressure sensors are directional. If your airspeed reads negative when blowing into the pitot tube, you can flip this parameter instead of physically swapping the silicone tubes.

## Parameter Breakdown

*   **`ARSPD_USE`**: Enable/Disable using this sensor for flight control.
*   **`ARSPD_TYPE`**: Driver type.
*   **`ARSPD_BUS`**: I2C bus number (0, 1, 2).
*   **`ARSPD_PIN`**: (Analog only) ADC Pin number.
*   **`ARSPD_RATIO`**: Calibration factor (Default ~2.0 for MS4525).
*   **`ARSPD_AUTOCAL`**: Enable in-flight learning.

## Integration Guide

### Pre-Flight Check
1.  **Cover:** Ensure pitot tube is uncovered.
2.  **Calibrate:** Perform "Preflight Calibration" in GCS to zero the pressure offset.
3.  **Blow Test:** Gently blow into the pitot tube. Speed should rise positive. If negative, toggle `ARSPD_TUBE_ORDR`.

### Tuning
1.  **Enable Autocal:** Set `ARSPD_AUTOCAL = 1`.
2.  **Fly:** Loiter in circles for 5 minutes.
3.  **Verify:** Check if `ARSPD_RATIO` has converged to a stable value.
4.  **Lock:** Set `ARSPD_AUTOCAL = 0` once tuned to prevent bad learning in turbulent conditions.

## Developer Notes
*   **Library:** `libraries/AP_Airspeed`
*   **Redundancy:** The `AP_Airspeed` library manages sensor switching and health monitoring (stuck pressure detection).
*   **Primary:** `ARSPD_PRIMARY` selects which sensor instance (0, 1, 2) is fed to the EKF.