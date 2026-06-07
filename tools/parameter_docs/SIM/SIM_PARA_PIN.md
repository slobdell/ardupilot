---
layout: parameter
name: SIM_PARA_PIN
display_name: Simulated Parachute Pin
description: The servo/GPIO pin that triggers the simulated parachute.
default_value: 0
range: 0 100
units: 
group: SIM
visual_asset_id: brd_io_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SIM_Parachute.cpp#L25
---

# Simulated Parachute Pin (SIM_PARA_PIN)

## Description
`SIM_PARA_PIN` connects the virtual parachute to an output channel.

Set this to match your `CHUTE_SERVO_ON` value. When that pin goes high, the simulator deploys the chute.