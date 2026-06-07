---
layout: parameter
name: GRIP_NEUTRAL
display_name: Neutral PWM
description: PWM value in microseconds sent to the grabber when not grabbing or releasing.
default_value: 1500
range: 1000 2000
units: PWM
group: GRIP
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Gripper/AP_Gripper.cpp
---

# Neutral PWM (GRIP_NEUTRAL)

## Description
The idle position for the gripper servo. For EPM, this is the "neutral" state where no power is being applied to the magnets.