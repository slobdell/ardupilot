---
layout: parameter
name: WRC_RATE_MAX
display_name: Wheel Rate Maximum
description: The maximum allowed rotation speed (in rad/s) for the wheels.
default_value: 0
range: 0 100
units: rad/s
group: WRC
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_WheelEncoder/AP_WheelRateControl.cpp#L17
---

# Wheel Rate Maximum (WRC_RATE_MAX)

## Description
`WRC_RATE_MAX` sets the physical speed limit for your wheels in the rate controller.