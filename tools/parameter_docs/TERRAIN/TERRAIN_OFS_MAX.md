---
layout: parameter
name: TERRAIN_OFS_MAX
display_name: Terrain Reference Offset Maximum
description: The maximum allowable correction (in meters) applied to align the terrain database with the vehicle's arming altitude.
default_value: 30
range: 0 50
units: m
group: TERRAIN
visual_asset_id: terrain_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Terrain/AP_Terrain.cpp#L79
---

# Terrain Reference Offset Maximum (TERRAIN_OFS_MAX)

## Description
`TERRAIN_OFS_MAX` is a sanity check for your map data.

When you arm the drone on the ground, ArduPilot checks the terrain database for the current location. Often, the map says the ground is at 100m, but the GPS/Baro says 105m. ArduPilot assumes the drone is on the ground and calculates an "Offset" (e.g. -5m) to shift the map to match reality. This parameter limits how large that shift can be.

## Tuning & Behavior
*   **Default:** 30 meters.
*   **Scenario:** If the map says you are at 100m elevation, but the GPS says 150m (a 50m error), and `TERRAIN_OFS_MAX` is 30, the system will reject the calibration because the map is likely wrong or the GPS glitch is too large.
*   **0:** Disables automatic terrain offset calibration.