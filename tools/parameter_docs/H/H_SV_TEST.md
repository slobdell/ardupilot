---
layout: parameter
name: H_SV_TEST
display_name: Boot-up Servo Test Cycles
description: Number of cycles to run servo test on boot-up.
default_value: 0
range: 0 10
units: 
group: H
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Motors/AP_MotorsHeli.cpp
---

# Boot-up Servo Test Cycles (H_SV_TEST)

## Description
Commands the swashplate servos to perform a pre-defined movement sequence upon power-up, allowing the pilot to visually confirm that all linkages are functioning correctly.
