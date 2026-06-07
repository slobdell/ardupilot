---
layout: parameter
name: H_RSC_GOV_COMP
display_name: Governor Torque Compensator
description: Determines how fast the governor will adjust the base torque reference to compensate for changes in density altitude.
default_value: 25
range: 0 70
units: %
group: H
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Motors/AP_MotorsHeli_RSC.cpp
---

# Governor Torque Compensator (H_RSC_GOV_COMP)

## Description
Adjusts the sensitivity of the governor's altitude compensation.
