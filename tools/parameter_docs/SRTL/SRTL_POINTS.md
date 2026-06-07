---
layout: parameter
name: SRTL_POINTS
display_name: SmartRTL maximum number of points on path
description: SmartRTL maximum number of points on path. Set to 0 to disable SmartRTL. 100 points consumes about 3k of memory.
default_value: 100
range: 0 500
units: 
group: SRTL
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_SmartRTL/AP_SmartRTL.cpp#L37
---

# SRTL_POINTS: SmartRTL maximum number of points on path

## Description
This parameter sets the memory limit for the "Smart RTL" (Return to Launch) path tracking.

## Values
- **Range:** 0 to 500
- **Default:** 100
- **Memory Cost:** ~3 KB per 100 points.

## Description
**Smart RTL** allows a drone to return home by replaying its outgoing path (like a breadcrumb trail), which is essential if you are flying in an area with obstacles (like buildings or trees) that would block a straight-line RTL.

- **Function:** As you fly, the autopilot saves your position as a series of "Points." This parameter limits how many points can be stored.
- **Out of Space:** If you fly a very long, complex path and run out of points, Smart RTL will simplify the older parts of the path by deleting intermediate breadcrumbs.
- **Disable:** Setting this to **0** completely disables the Smart RTL feature to save RAM on memory-constrained boards.
- **Reboot Required:** Changes to this parameter require a reboot to reallocate memory.

