# GPS Minimum Constraints (GPSMIN)

## Overview
The **GPSMIN** parameter group (specifically `GPS_MIN_ELEV`) defines the minimum thresholds for a valid GPS satellite to be used in the solution.

## Key Concepts

### 1. Mask Elevation
Satellites near the horizon have to transmit through more atmosphere, which introduces noise and timing errors.
*   **`GPS_MIN_ELEV`**: Defines the angle (in degrees) above the horizon below which satellites are ignored.
    *   **Typical:** 10 to 15 degrees.

## Developer Notes
*   **Library:** `libraries/AP_GPS`.