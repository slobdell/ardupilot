---
layout: parameter
name: SIM_SF_JS_STICK
display_name: Simulation SFML Joystick Index
description: The ID of the physical joystick/gamepad to use in SITL (via SFML).
default_value: 0
range: 0 7
units: 
group: SIM
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/SITL/SITL.cpp#L1082
---

# Simulation SFML Joystick Index (SIM_SF_JS_STICK)

## Description
`SIM_SF_JS_STICK` selects which physical joystick or gamepad connected to your computer is used to control the simulated vehicle in SITL. 

This is used by the SFML (Simple and Fast Multimedia Library) backend of SITL. If you have multiple controllers connected, you may need to change this ID to select the correct one.

## Tuning & Behavior
*   **Default:** 0.
*   **Usage:** Set to 0 for the first detected controller, 1 for the second, and so on.