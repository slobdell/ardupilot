---
layout: parameter
name: SIM_WOW_PIN
display_name: Simulated Weight on Wheels Pin
description: The GPIO pin number assigned to the simulated Weight on Wheels (WoW) sensor.
default_value: -1
range: -1 100
units: 
group: SIM
visual_asset_id: brd_io_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated Weight on Wheels Pin (SIM_WOW_PIN)

## Description
`SIM_WOW_PIN` enables a virtual sensor that detects if the aircraft is physically touching the ground.

This is critical for testing automatic arming/disarming logic and "Landed" state detection. When the drone is on the ground, the virtual pin state is changed.

## Tuning & Behavior
*   **Default Value:** -1 (Disabled).