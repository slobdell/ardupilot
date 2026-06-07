---
layout: parameter
name: JS_THR_GAIN
display_name: Joystick Throttle Gain
description: A dedicated multiplier for the throttle axis when using a joystick.
default_value: 1.0
range: 0.1 1.0
units: 
group: JS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduSub/Parameters.cpp#L273
---

# Joystick Throttle Gain (JS_THR_GAIN)

## Description
`JS_THR_GAIN` allows you to independently scale the throttle sensitivity without affecting the rotation or lateral axes.