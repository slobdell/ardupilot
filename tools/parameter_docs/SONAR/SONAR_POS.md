---
layout: parameter
name: SONAR_POS
display_name: Sonar position
description: Position of the sonar sensor in body frame.
default_value: 0
range: -5 5
units: m
group: SONAR
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L239
---

# SONAR_POS: Sonar position

## Description
This parameter (SITL only) defines the physical location of the simulated sonar sensor relative to the vehicle's center of gravity (CG).

## Values
- **Range:** -5 to 5
- **Units:** Meters (m)
- **Default:** 0.0, 0.0, 0.0

## Description
`SONAR_POS` allows for realistic simulation of rangefinder offsets.

- **Function:** If the sonar is mounted 20cm forward of the CG, you would set the X component to **0.2**. 
- **Effect:** The simulation will calculate the distance to the ground from that specific point rather than the center of the aircraft, which is important for accurate landing and terrain-following behavior when the drone is pitched or rolled.
- **Components:** This is a Vector3f parameter (X, Y, Z).

