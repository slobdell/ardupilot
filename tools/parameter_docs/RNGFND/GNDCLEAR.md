---
layout: parameter
name: GNDCLEAR
display_name: Rangefinder Ground Clearance
description: The distance (in cm) from the rangefinder to the ground when the vehicle is at rest.
default_value: 10
range: 1 100
units: cm
group: RNGFND
visual_asset_id: rngfnd_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_RangeFinder/AP_RangeFinder_Params.cpp#L100
---

# Rangefinder Ground Clearance (GNDCLEAR)

## Description
`GNDCLEAR` tells the autopilot how high the Lidar sensor is sitting when the drone is on the ground.

When the drone is stationary on its landing gear, the Lidar reading isn't zero (because the sensor is usually a few centimeters off the dirt). This parameter allows the flight controller to subtract that height so that the reported "Altitude" is exactly zero on the ground.

## Tuning & Behavior
*   **Default Value:** 10 cm.
*   **Recommendation:** Measure the distance from the sensor face to the floor and enter it here.
