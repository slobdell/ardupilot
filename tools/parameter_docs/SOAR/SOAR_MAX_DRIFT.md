---
layout: parameter
name: SOAR_MAX_DRIFT
display_name: Maximum drift distance to allow when thermalling
description: The previous mode will be restored if the horizontal distance to the thermalling start location exceeds this value. -1 to disable.
default_value: -1
range: 0 1000
units: m
group: SOAR
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Soaring/AP_Soaring.cpp#L127
---

# SOAR_MAX_DRIFT: Maximum drift distance to allow when thermalling

## Description
The previous mode will be restored if the horizontal distance to the thermalling start location exceeds this value. -1 to disable.

## Values
- **Range:** 0 to 1000
- **Units:** m
- **Default:** -1 (Disabled)

## Description
This parameter defines a "Geofence" for autonomous thermalling.

- **Function:** When the glider detects lift and enters `THERMAL` mode, it starts circling. The wind will naturally push the thermal (and the glider) downwind.
- **Safety:** If the glider drifts too far from the point where it started thermalling, it might get blown too far downwind to return home safely. `SOAR_MAX_DRIFT` sets the maximum allowable distance.
- **Trigger:** If exceeded, the glider exits `THERMAL` mode and resumes its previous navigation task (e.g., `AUTO` waypoints or `CRUISE`).

