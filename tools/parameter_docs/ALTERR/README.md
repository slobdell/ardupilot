# Altitude Error Checks (ALTERR)

## Overview
The **ALTERR** parameter group (often appearing as `BARO_ALTERR_` in the full parameter list) configures the pre-flight safety checks related to altitude consistency.

Before allowing the vehicle to arm, the autopilot compares the altitude reported by the Barometer against the altitude reported by the GPS. Large discrepancies indicate a potential sensor failure, blockage (pitot/static port), or extreme weather changes, which could lead to dangerous behavior if the EKF (State Estimator) cannot reconcile the data.

## Key Concepts

### 1. Altitude Discrepancy Check (`ALTERR_MAX`)
This parameter sets the threshold for the difference between the two altitude sources.
*   **Logic:** `if abs(BaroAlt - GPSAlt) > ALTERR_MAX: PRE-ARM FAILURE`
*   **Common Error:** "GPS alt error [X]m (see BARO_ALTERR_MAX)"

### 2. Sensor Health
This check helps identify:
*   **Drifting Barometers:** Due to temperature changes or sunlight hitting the sensor.
*   **Bad GPS Vertical Accuracy:** Poor satellite geometry.
*   **Pressurized Compartments:** If the flight controller is sealed in a box that pressurizes as it heats up.

## Parameter Breakdown

*   **`ALTERR_MAX`** (or `BARO_ALTERR_MAX`): Maximum allowable error in meters (or centimeters, check units). Default is typically 2000 (20 meters).

## Integration Guide

### Troubleshooting Pre-Arm Failures
1.  **Check GPS:** Ensure you have a 3D Lock and low HDOP/VDOP. GPS altitude is notoriously noisy indoors.
2.  **Calibrate:** Perform a barometer calibration (reboot) if the vehicle has moved significant elevation since power-on.
3.  **Adjust Threshold:** If you are operating in a challenging environment (e.g., indoors with GPS repeaters), you may need to increase `ALTERR_MAX` to bypass the check, but this increases the risk of EKF instability.

## Developer Notes
*   **Library:** `libraries/AP_Baro`
*   **Implementation:** The check is performed within the `AP_Baro::update()` loop or the `AP_Arming` library.