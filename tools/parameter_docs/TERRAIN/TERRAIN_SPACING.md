---
layout: parameter
name: TERRAIN_SPACING
display_name: Terrain Grid Spacing
description: The horizontal distance (in meters) between terrain data points requested from the GCS.
default_value: 100
range: 30 1000
units: m
group: TERRAIN
visual_asset_id: terrain_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Terrain/AP_Terrain.cpp#L56
---

# Terrain Grid Spacing (TERRAIN_SPACING)

## Description
`TERRAIN_SPACING` defines the "Resolution" of the map used by the autopilot.

When the drone flies into a new area, it asks the Ground Control Station (GCS) for terrain height data. This parameter tells the GCS how dense that data should be.

*   **100m (Default):** A good balance. The drone requests the height of the ground every 100 meters. This matches the standard SRTM database resolution used by Mission Planner.
*   **30m:** High resolution. Useful for very detailed low-level flying, but uses more SD card space and telemetry bandwidth.

## Tuning & Behavior
*   **Default:** 100.
*   **Recommendation:** Leave at **100**. Setting it lower than your GCS's actual map data (e.g. asking for 10m spacing when the map is only 90m resolution) is wasteful and provides no extra accuracy.