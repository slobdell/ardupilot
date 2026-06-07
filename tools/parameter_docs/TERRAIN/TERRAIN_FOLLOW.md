---
layout: parameter
name: TERRAIN_FOLLOW
display_name: Enable Terrain Following
description: Enables terrain following for assisted flight modes (CRUISE, FBWB, RTL) and Rally points.
default_value: 0
range: 0 1
units: 
group: TERRAIN
visual_asset_id: terrain_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduPlane/Parameters.cpp#L336
---

# Enable Terrain Following (TERRAIN_FOLLOW)

## Description
`TERRAIN_FOLLOW` switches the autopilot's altitude reference from "Above Home" to "Above Ground Level (AGL)" for semi-autonomous modes.

When enabled, modes like **CRUISE** and **FBWB** (Fly-By-Wire B) will attempt to maintain a constant height above the terrain rather than a constant barometric altitude. This is essential for low-level flying in hilly environments.

*   **0: Disabled.** Altitude is relative to the home takeoff point.
*   **1: Enabled.** Altitude is relative to the terrain database or rangefinder reading.

## Tuning & Behavior
*   **Default:** 0.
*   **Safety:** You **MUST** have valid terrain data (on SD card) or a long-range lidar for this to work safely. If the terrain data is missing, the plane may climb unexpectedly (failsafe) or fly into a hill.
*   **RTL:** This also affects Return-to-Launch. The plane will climb over hills on its way home.