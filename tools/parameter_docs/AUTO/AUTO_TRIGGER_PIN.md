---
layout: parameter
name: AUTO_TRIGGER_PIN
display_name: Auto Mode Trigger Pin
description: The GPIO pin used to trigger the start of an AUTO mission.
default_value: -1
range: -1 103
units: 
group: AUTO
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/Rover/Parameters.cpp
---

# Auto Mode Trigger Pin (AUTO_TRIGGER_PIN)

## Description
`AUTO_TRIGGER_PIN` allows a physical button or external signal to start the autonomous mission.