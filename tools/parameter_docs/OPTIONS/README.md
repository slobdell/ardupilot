# Global and Subsystem Options (OPTIONS)

## Overview
The **OPTIONS** parameter group is a generic container for bitmask settings that toggle specific features within a library or vehicle.

Because many ArduPilot features are "On/Off" toggles, the developers group them into `OPTIONS` bitmasks to save space in the parameter table.

## Common Options Groups
*   **`GPS_DRV_OPTIONS`**: Workarounds for specific GPS chips.
*   **`FENCE_OPTIONS`**: Behavior of the geofence (e.g., enable on arming).
*   **`EK3_SRC_OPTIONS`**: Sources for EKF3 (e.g., use compass or GPS for yaw).
*   **`FLIGHT_OPTIONS`**: Global flight behavior overrides.

## Parameter Breakdown

*   **`OPTIONS`**: (The specific context depends on the parent folder).
    *   Refer to the ArduPilot documentation for the specific meaning of each bit (Bit 0, Bit 1, etc.) for the subsystem you are investigating.

## Developer Notes
*   **Bitmasking:** To enable multiple options, you must add their values together (e.g., to enable Option 1 (value 1) and Option 3 (value 4), set the parameter to 5).