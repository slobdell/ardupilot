---
layout: parameter
name: BAL_PIT_FF
display_name: Balance Bot Pitch to Throttle FeedForward
description: Pitch to throttle feed forward gain for balance bots.
default_value: 0.5
range: 0 1
units: 
group: BAL
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/APM_Control/AR_AttitudeControl.cpp
---

# Balance Bot Pitch to Throttle FeedForward (BAL_PIT_FF)

## Description
Feed-forward gain that couples pitch error directly to motor throttle in balance bot configurations, improving stability.