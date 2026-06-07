---
layout: parameter
name: OSD1_CHAN_MAX
display_name: OSD Screen Switch PWM Max (Instance 1)
description: The maximum PWM value on the OSD_CHAN to select this screen.
default_value: 2100
range: 900 2100
units: PWM
group: OSD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_OSD/AP_OSD_Screen.cpp#L83
---

# OSD Screen Switch PWM Max (OSD1_CHAN_MAX)

## Description
Defines the upper PWM limit for selecting this OSD screen.