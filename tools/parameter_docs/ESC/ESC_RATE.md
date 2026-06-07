---
layout: parameter
name: ESC_RATE
display_name: ESC Update Rate
description: Rate in Hz that ESC PWM outputs (function is MotorN) will update at.
default_value: 400
range: 50 400
units: Hz
group: ESC
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/Tools/AP_Periph/Parameters.cpp
---

# ESC Update Rate (ESC_RATE)

## Description
Defines the output refresh rate for traditional PWM-based ESCs on an AP_Periph node.