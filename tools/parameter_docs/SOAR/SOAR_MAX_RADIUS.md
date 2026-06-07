---
layout: parameter
name: SOAR_MAX_RADIUS
display_name: Maximum thermal radius
description: Maximum radius to allow the thermal to grow to. If the radius estimate exceeds this value then thermalling is stopped.
default_value: 200
range: 0 500
units: m
group: SOAR
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Soaring/AP_Soaring.cpp#L137
---

# SOAR_MAX_RADIUS: Maximum thermal radius

## Description
Maximum radius to allow the thermal to grow to. If the radius estimate exceeds this value then thermalling is stopped.

## Values
- **Range:** 0 to 500
- **Units:** m
- **Default:** 200

## Description
This parameter limits the size of the circling pattern when soaring.

- **Function:** The Soaring EKF constantly estimates the size and strength of the thermal.
- **Trigger:** If the estimated size of the thermal core grows larger than this radius, the autopilot assumes the lift is too diffuse or the estimate is invalid, and it abandons the thermal to continue the mission.
