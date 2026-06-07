---
layout: parameter
name: SIM_PLD_DIST_LMT
display_name: Simulation Precision Landing Lateral Range
description: The maximum horizontal distance (in meters) from the target at which the sensor can detect it.
default_value: 10
range: 0 100
units: m
group: SIM
visual_asset_id: plnd_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/SITL/SIM_Precland.cpp#L102
---

# Simulation Precision Landing Lateral Range (SIM_PLD_DIST_LMT)

## Description
`SIM_PLD_DIST_LMT` simulates the "Field of View" (FOV) constraint of your Precision Landing sensor.

Cameras and IR sensors can only see a certain width. If the drone is too far to the side of the target, the beacon will fall out of the camera's frame. This parameter sets that lateral limit in meters.

## Tuning & Behavior
*   **Default:** 10 meters.
*   **Physics:** This creates a virtual "cone" or cylinder of detection above the target. If the horizontal distance between the drone and the [SIM_PLD_LAT/LON](SIM_PLD_LAT.html) target is greater than this value, the sensor reports "No Target."