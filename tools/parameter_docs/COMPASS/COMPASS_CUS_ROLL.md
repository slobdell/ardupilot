---
layout: parameter
name: COMPASS_CUS_ROLL
display_name: Custom orientation roll offset
description: Compass mounting position roll offset.
default_value: 0
range: -180 180
units: deg
group: COMPASS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Compass/AP_Compass.cpp
---

# Custom orientation roll offset (COMPASS_CUS_ROLL)

## Description
Allows for precise, degree-by-degree compensation of the compass mounting angle in the roll axis.
*   **Only active if COMPASS_ORIENT is set to 100 (Custom).**
