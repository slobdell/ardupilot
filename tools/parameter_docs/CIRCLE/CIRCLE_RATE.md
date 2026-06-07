---
layout: parameter
name: CIRCLE_RATE
display_name: Circle rate
description: Circle mode's turn rate in deg/sec. Positive to turn clockwise, negative for counter clockwise.
default_value: 20
range: -90 90
units: deg/s
group: CIRCLE
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AC_WPNav/AC_Circle.cpp
---

# Circle rate (CIRCLE_RATE)

## Description
Defines the angular speed and direction of the vehicle's movement around the circle.

## Tuning & Behavior
*   **Default Value:** 20 deg/s
*   **Range:** -90 to 90 deg/s
*   **Positive values result in clockwise rotation; negative values result in counter-clockwise rotation.**