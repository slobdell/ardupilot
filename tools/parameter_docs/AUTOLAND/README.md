# Autoland Configuration (AUTOLAND)

## Overview
The **AUTOLAND** parameter group appears to contain legacy or alias parameters related to the Automatic Landing sequence in ArduPlane.

**Note:** In modern ArduPilot firmware, most landing configuration is handled by:
*   **`LAND_`** group: For Copter landing speeds.
*   **`TECS_`** group: For Plane glide slope and descent rates.
*   **`RTL_AUTOLAND`**: To trigger landing after RTL.
*   **Mission Items:** `DO_LAND_START`, `NAV_LAND` waypoints.

## Key Parameters (Legacy/Reference)

*   **`AUTOLAND_WP_ALT`**: Likely referred to the altitude of the final approach waypoint.
*   **`AUTOLAND_OPTIONS`**: Bitmask for behavior (e.g., flare logic).

## Integration Guide
For setting up Auto Landing in modern firmware:
1.  **Plane:** Use a mission with `DO_LAND_START` -> `NAV_LOITER_TO_ALT` -> `NAV_LAND`.
2.  **Copter:** Use `LAND_SPEED` and `LAND_SPEED_HIGH` to tune the descent.

## Developer Notes
*   These parameters may not exist in the current `ardupilot` codebase and might be artifacts of older documentation generation.