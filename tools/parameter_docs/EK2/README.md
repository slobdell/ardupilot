# Extended Kalman Filter 2 (EK2)

## Overview
The **EK2** parameter group configures the **Legacy EKF2** state estimator. For many years, this was the default navigation filter for ArduPilot. It fuses data from IMUs, GPS, Barometers, and Compasses to determine Position, Velocity, and Attitude.

**Note:** As of ArduPilot 4.1+, EKF3 (`EK3`) is the default. EKF2 is kept for legacy compatibility on F4 boards where EKF3 might be too heavy, or for users who trust its proven track record.

## Key Concepts

### 1. Source Switching (`EK2_GPS_TYPE`, `EK2_ALT_SOURCE`)
EKF2 allows selecting primary sources, but it is less flexible than EKF3.
*   **GPS Type:** 0=GPS 3D Vel, 1=GPS 2D Vel, etc.
*   **Alt Source:** 0=Baro, 1=Rangefinder, 2=GPS, 3=Beacon.

### 2. Innovation Gates (`_I_GATE`)
The filter rejects sensor data that deviates too far from the current estimate.
*   **`EK2_POS_I_GATE`**: How many standard deviations a GPS position update can "jump" before being rejected as a glitch.

### 3. Noise Parameters (`_M_NSE`, `_P_NSE`)
Tuning parameters representing the expected noise of the sensors.
*   **Increase** if your sensors are noisy/vibrating (trusts the sensor less).
*   **Decrease** if you have high-end sensors (trusts the sensor more).

## Parameter Breakdown

*   **`EK2_ENABLE`**: Master switch.
*   **`EK2_IMU_MASK`**: Selects which IMUs to use (1=IMU1, 2=IMU2, 3=Both).
*   **`EK2_MAG_CAL`**: EKF2 can learn magnetometer offsets in flight.

## Integration Guide
*   **Selection:** To use EKF2, set `AHRS_EKF_TYPE = 2` and `EK2_ENABLE = 1`.
*   **Tuning:** Generally, default parameters work for 99% of vehicles. Modifying noise parameters is only for advanced users with specific vibration issues.

## Developer Notes
*   **Library:** `libraries/AP_NavEKF2`
*   **States:** 22-state filter.