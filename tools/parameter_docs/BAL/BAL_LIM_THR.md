---
layout: parameter
name: BAL_LIM_THR
display_name: Balance Bot Pitch Limit Throttle Threshold
description: Throttle threshold above which pitch limiting is active on a balance bot.
default_value: 0.7
range: 0.1 1.0
units: 
group: BAL
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/APM_Control/AR_AttitudeControl.cpp
---

# Balance Bot Pitch Limit Throttle Threshold (BAL_LIM_THR)

## Description
Defines the throttle level at which the balance bot begins to prioritize maintaining its upright balance over following the speed command.