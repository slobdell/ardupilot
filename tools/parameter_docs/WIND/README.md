# Wind Estimation Configuration (WIND)

## Overview
The **WIND** parameter group (specifically `WIND_MAX`) configures the safety limits for wind speed.

## Key Concepts

### 1. Wind Limit (`WIND_MAX`)
(ArduPlane) Defines the maximum wind speed (m/s) that the autopilot is allowed to attempt to fly in.
*   **Action:** If the estimated environmental wind exceeds this value, the autopilot may trigger a warning or refuse to start a mission.

## Developer Notes
*   **Library:** `libraries/AP_AHRS`.
*   **Estimation:** Wind is estimated by subtracting the Airspeed vector from the GPS Ground Speed vector.