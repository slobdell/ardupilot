---
layout: parameter
name: H_RSC_IDLE
display_name: Throttle Output at Idle
description: Throttle output in percent while armed but motor interlock is disabled.
default_value: 0
range: 0 50
units: %
group: H
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Motors/AP_MotorsHeli_RSC.cpp
---

# Throttle Output at Idle (H_RSC_IDLE)

## Description
Defines the engine idle throttle for combustion-powered helicopters. For electric helicopters, this is typically set to 0.
