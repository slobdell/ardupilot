# Terrain Following Configuration (TERRAIN)

## Overview
The **TERRAIN** parameter group configures the **Terrain Following** system. This library allows the vehicle to maintain a constant height above the ground during autonomous missions by referencing a global terrain database stored on the SD card.

Unlike Lidar-based avoidance, Terrain Following uses pre-recorded topographic maps (SRTM data) and does not require an active sensor to see the ground (though it can be used together).

## Key Concepts

### 1. The Terrain Database
The GCS (Mission Planner) downloads terrain data for your mission area and uploads it to the autopilot's SD card.
*   **`TERRAIN_SPACING`**: The resolution (meters) of the grid points. Smaller values provide more detail but consume more memory.

### 2. Following Logic (`TERRAIN_FOLLOW`)
Determines if the vehicle uses terrain data for altitude control.
*   **Disabled:** All altitudes are relative to the home/takeoff point.
*   **Enabled:** Waypoint altitudes are treated as "Above Ground Level" (AGL). The drone will climb and descend as the terrain rises and falls.

### 3. Lookahead (`TERRAIN_LOOKAHD`)
The autopilot calculates the terrain height ahead of the vehicle to start climbing *before* it hits a hill, rather than reacting only when it arrives.

## Parameter Breakdown

*   **`TERRAIN_ENABLE`**: Master switch.
*   **`TERRAIN_MARGIN`**: Vertical safety buffer.
*   **`TERRAIN_CACHE_SZ`**: RAM allocated for holding terrain tiles.

## Integration Guide
1.  **Preparation:** Ensure your flight controller has an SD card.
2.  **Enable:** Set `TERRAIN_ENABLE = 1`.
3.  **Download:** Use Mission Planner to "Pre-fetch" terrain for your intended flight area while your laptop has internet.
4.  **Planning:** In your mission, set the altitude type to "Terrain."

## Developer Notes
*   **Library:** `libraries/AP_Terrain`.
*   **Safety:** Always set `FENCE_ALT_MAX` as a global backup. Terrain data can have errors (e.g., missing trees or buildings).