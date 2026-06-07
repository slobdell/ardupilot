---
layout: parameter
name: CIRCLE_RADIUS
display_name: Circle Radius
description: Defines the radius of the circle the vehicle will fly when in Circle flight mode.
default_value: 1000
range: 0 200000
units: cm
group: CIRCLE
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AC_WPNav/AC_Circle.cpp
---

# Circle Radius (CIRCLE_RADIUS)

## Description
Specifies the horizontal distance from the center point that the vehicle will maintain while in the "Circle" flight mode.

## Tuning & Behavior
*   **Default Value:** 1000 cm (10 m)
*   **Range:** 0 to 200,000 cm
*   **A value of 0 results in the vehicle performing a "Panorama" (rotating in place).**