---
layout: parameter
name: H_COL_MAX
display_name: Maximum Collective Pitch
description: Highest possible servo position in PWM microseconds for the swashplate.
default_value: 1750
range: 1000 2000
units: PWM
group: H
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Motors/AP_MotorsHeli.cpp
---

# Maximum Collective Pitch (H_COL_MAX)

## Description
Defines the maximum physical travel limit of the swashplate for collective pitch control.
