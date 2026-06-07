---
layout: parameter
name: SIM_VOLZ_ENA
display_name: Simulation Volz Servo Enable
description: Enables the simulation of Volz serial protocol servos.
default_value: 0
range: 0 1
units: 
group: SIM
visual_asset_id: servo_volz_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L130
---

# Simulation Volz Servo Enable (SIM_VOLZ_ENA)

## Description
`SIM_VOLZ_ENA` activates the simulated driver for Volz digital servos.

Normally, SITL assumes standard PWM servos. If you enable this, ArduPilot will communicate with virtual Volz servos via a serial protocol, allowing you to test the serial driver and telemetry feedback in a simulated environment.