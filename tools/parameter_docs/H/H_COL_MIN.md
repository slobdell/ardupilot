---
layout: parameter
name: H_COL_MIN
display_name: Minimum Collective Pitch
description: Lowest possible servo position in PWM microseconds for the swashplate.
default_value: 1250
range: 1000 2000
units: PWM
group: H
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Motors/AP_MotorsHeli.cpp
---

# Minimum Collective Pitch (H_COL_MIN)

## Description
Defines the minimum physical travel limit of the swashplate for collective pitch control. 
