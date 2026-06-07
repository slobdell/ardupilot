---
layout: parameter
name: FS_TERRAIN_ENAB
display_name: Terrain Failsafe Enable
description: Controls the behavior when terrain data is lost during an autonomous mission.
default_value: 0
range: 0 2
units: 
group: FS
visual_asset_id: terrain_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduCopter/Parameters.cpp
---

# Terrain Failsafe Enable (FS_TERRAIN_ENAB)

## Description
`FS_TERRAIN_ENAB` defines the "Safety Net" for terrain-following missions. 

If you are flying an autonomous mission where the drone's altitude is relative to the ground (Terrain Following), the autopilot requires a steady stream of terrain data (from the SD card or a rangefinder). If this data is lost (e.g., SD card error or flying into an area with no map coverage), this parameter tells the drone how to react.

*   **0: Disarm/Land.** (Standard for some vehicles).
*   **1: RTL.** Immediately returns home using Barometric (standard) altitude.
*   **2: Continue.** (Risky). Switch to barometric altitude and continue the mission at the current height above home.

## Tuning & Behavior
*   **Default:** 0.
*   **Recommendation:** Set to **1 (RTL)** to ensure the drone returns to a safe location if it can no longer "see" the ground profile.