# MAVLink System Identification (SYSID)

## Overview
The **SYSID** parameter group configures the identifiers used in MAVLink communication. These IDs ensure that multiple vehicles and ground stations can operate on the same radio network without conflicting.

## Key Concepts

### 1. This Vehicle (`SYSID_THISMAV`)
Assigns a unique ID to the autopilot.
*   **Default:** 1.
*   **Recommendation:** If flying in a swarm or group, every drone must have a unique `SYSID_THISMAV` (e.g., 1, 2, 3...).

### 2. My GCS (`SYSID_MYGCS`)
Defines the ID of the Ground Control Station that the autopilot should trust for critical commands (like arming or parameter changes).
*   **Default:** 255.

### 3. Enforce Identity (`SYSID_ENFORCE`)
If enabled, the autopilot will only accept commands from the specific GCS defined in `SYSID_MYGCS`.

## Developer Notes
*   **Library:** `libraries/GCS_MAVLink`.
*   **Range:** 1 to 255.