---
layout: parameter
name: BAL_LIM_TC
display_name: Balance Bot Pitch Limit Time Constant
description: Time constant for the pitch limit filter on a balance bot.
default_value: 0.5
range: 0.1 2.0
units: s
group: BAL
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/APM_Control/AR_AttitudeControl.cpp
---

# Balance Bot Pitch Limit Time Constant (BAL_LIM_TC)

## Description
Smoothing factor for the pitch limiting logic in Rover Balance Bots.