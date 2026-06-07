---
layout: parameter
name: H_CYC_MAX
display_name: Maximum Cyclic Pitch Angle
description: Maximum cyclic pitch angle of the swash plate.
default_value: 4500
range: 0 4500
units: 
group: H
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Motors/AP_MotorsHeli.cpp
---

# Maximum Cyclic Pitch Angle (H_CYC_MAX)

## Description
Defines the maximum angular authority of the swashplate for roll and pitch maneuvers.
*   **Typically adjusted to achieve 6-7 degrees of physical blade pitch change.**
