---
layout: parameter
name: BAL_PITCH_TRIM
display_name: Balance Bot Pitch Trim
description: Pitch angle trim for balance bots to achieve stationary balance.
default_value: 0
range: -5 5
units: deg
group: BAL
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/Rover/Parameters.cpp
---

# Balance Bot Pitch Trim (BAL_PITCH_TRIM)

## Description
Fine-tuning adjustment to the "center of gravity" for a balance bot, used to ensure it stays perfectly stationary when no movement is commanded.