---
layout: parameter
name: CHUTE_DELAY_MS
display_name: Parachute release delay
description: Delay in milliseconds between motor stop and chute release.
default_value: 500
range: 0 5000
units: ms
group: CHUTE
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Parachute/AP_Parachute.cpp
---

# Parachute release delay (CHUTE_DELAY_MS)

## Description
Pause duration between the command to stop the motors (to prevent entanglement) and the actual release of the parachute.