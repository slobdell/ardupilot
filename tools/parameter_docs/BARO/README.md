# Barometer Configuration (BARO)

## Overview
The **BARO** parameter group configures the **Barometric Pressure Sensors** (Barometers). These sensors measure atmospheric pressure to estimate the vehicle's **Altitude** relative to the launch point (AGL).

Barometers are the primary altitude source for most flight modes (AltHold, Loiter, Auto). They are sensitive to:
1.  **Light:** Sunlight striking the sensor element can cause jumps (cover with open-cell foam).
2.  **Wind/Prop Wash:** Airflow over the sensor creates pressure variations (Bernoulli effect), leading to altitude errors.
3.  **Temperature:** Drift occurs as the board heats up.

## Key Concepts

### 1. Primary Sensor (`BARO_PRIMARY`)
ArduPilot supports up to 3 redundant barometers. This parameter selects which one is trusted by the EKF (State Estimator) by default.
*   **0:** First detected (Internal).
*   **1:** Second detected.
*   **2:** Third detected.

### 2. Ground Reference (`BARO_GND_TEMP`)
The barometer calculates altitude based on the temperature and pressure measured on the ground during arming.
*   **`BARO_FIELD_ELV`**: Allows manually setting the takeoff elevation (AMSL) if known, to improve absolute altitude reporting.

### 3. Wind Compensation (`BARO1_WCF_...`)
These parameters provide **Wind Coefficient corrections**. If your drone's altitude reading changes significantly when flying forward vs. hovering (due to dynamic pressure build-up inside the fuselage), you can tune these coefficients to subtract the speed-induced pressure error.

## Parameter Breakdown

*   **`BARO_ENABLE`**: Master switch.
*   **`BARO_PRIMARY`**: Active sensor selector.
*   **`BARO_ALT_OFFSET`**: Calibration offset (tuning).
*   **`BARO_ALTERR_MAX`**: Maximum allowed difference between GPS and Baro altitude before pre-arm failure.
*   **`BARO_PROBE_EXT`**: Probe for external I2C barometers (BMP280, DPS310, etc.).

## Integration Guide

### Hardware Setup
*   **Foam:** ALWAYS cover the barometer chip on the flight controller with open-cell foam and a breathable case to shield it from light and direct airflow.
*   **External:** If the internal baro is noisy or subject to heat, use an external DroneCAN or I2C barometer mounted in a better location.

### Troubleshooting "Baro Drift"
*   If altitude rises while the drone is sitting on the bench: **Thermal Drift**. Wait for the board to warm up before flying.
*   If altitude drops when you throttle up: **Prop Wash**. Improve isolation/foam.
*   If altitude changes when flying fast: **Dynamic Pressure**. Tune `WCF` params or move the static port.

## Developer Notes
*   **Library:** `libraries/AP_Baro`
*   **Singleton:** `AP_Baro::get_singleton()`
*   **Drivers:** Supports MS5611, BMP280, DPS310, ICP10100, and many others.