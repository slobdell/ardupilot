---
layout: parameter
name: JS_LIGHTS_STEPS
display_name: Joystick Lights Steps
description: The number of increments (steps) for adjusting the brightness of ROV lights via a joystick button.
default_value: 8
range: 1 20
units: Steps
group: JS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduSub/Parameters.cpp#L266
---

# Joystick Lights Steps (JS_LIGHTS_STEPS)

## Description
`JS_LIGHTS_STEPS` sets the "Brightness Increments" for ROV external lights.

When you use a joystick button to dim or brighten your underwater lights, this parameter defines how much the brightness changes per click.