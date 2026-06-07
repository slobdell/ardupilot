---
layout: parameter
name: STOP_DIST
display_name: Distance from docking target when we should stop
description: The vehicle starts stopping when it is this distance away from docking target.
default_value: 0.3
range: 0 2
units: m
group: STOP
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/Rover/mode_dock.cpp#L46
---

# STOP_DIST: Distance from docking target when we should stop

## Description
The vehicle starts stopping when it is this distance away from docking target.

## Values
- **Range:** 0 to 2
- **Units:** m
- **Default:** 0.3

## Description
This parameter is used in the **Docking Mode** for Rovers and Boats.

- **Function:** It defines the "Stopping Point" offset from the target. The vehicle will aim to come to a complete halt at this distance *before* hitting the physical dock or charging station.
- **Safety:** Prevents collision with the docking infrastructure.
- **Tuning:** Adjust based on the physical size of your vehicle and the tolerance of your docking mechanism.

