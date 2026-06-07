---
layout: parameter
name: BRD_VSERVO_MIN
display_name: Servo voltage requirement
description: Minimum voltage on the servo rail to allow the aircraft to arm. 0 to disable the check.
default_value: 0
range: 3.3 12.0
units: V
group: BRD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_BoardConfig/AP_BoardConfig.cpp
---

# Servo voltage requirement (BRD_VSERVO_MIN)

## Description
Pre-arm safety threshold for the servo power rail. Arming is blocked if the voltage powering the servos is below this value.