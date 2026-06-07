---
layout: parameter
name: OSD1_CHAN_MIN
display_name: OSD Screen Switch PWM Min (Instance 1)
description: The minimum PWM value on the OSD_CHAN to select this screen.
default_value: 900
range: 900 2100
units: PWM
group: OSD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_OSD/AP_OSD_Screen.cpp#L76
---

# OSD Screen Switch PWM Min (OSD1_CHAN_MIN)

## Description
`OSD1_CHAN_MIN` (and `OSD1_CHAN_MAX`) defines the PWM "Window" that activates this specific OSD screen.

If [OSD_SW_METHOD](OSD_SW_METHOD.html) is set to **1 (PWM_RANGE)**, the autopilot looks at the current value of the [OSD_CHAN](OSD_CHAN.html). If the value is between MIN and MAX for a screen, that screen is shown.