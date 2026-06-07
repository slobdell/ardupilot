---
layout: parameter
name: OSD_W_TERR
display_name: OSD Terrain Height Warning
description: The height (in meters) above terrain at which the OSD will start flashing a warning.
default_value: -1
range: -1 1000
units: m
group: OSD
visual_asset_id: osd_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_OSD/AP_OSD.cpp#L186
---

# OSD Terrain Height Warning (OSD_W_TERR)

## Description
`OSD_W_TERR` is a "Low Altitude" alarm based on terrain data. 

If the drone is equipped with terrain data (on the SD card) or a long-range distance sensor, it knows its height above the ground. If that height falls below this value, the terrain height readout on your screen will flash to warn you of a potential ground collision.

*   **-1:** Disabled (Default).
*   **Value (m):** Height in meters at which the warning triggers.

## Tuning & Behavior
*   **Recommendation:** Set to **10** or **20** meters if you are flying in hilly terrain to provide an early warning of rising ground.
*   **Prerequisite:** Requires a valid terrain database or a functional rangefinder.