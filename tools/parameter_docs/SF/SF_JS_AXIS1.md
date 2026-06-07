---
layout: parameter
name: SF_JS_AXIS1
display_name: SFML Joystick Axis 1
description: Maps a physical joystick axis (from SFML) to an autopilot RC channel.
default_value: 0
range: 0 8
units: 
group: SF
visual_asset_id: joystick_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# SFML Joystick Axis 1 (SF_JS_AXIS1)

## Description
`SF_JS_AXIS1` allows you to use a real USB Joystick or Gamepad to fly the simulator.

If you are using the SFML build of SITL, this parameter maps the first axis of your physical controller to the internal RC input system.

## Tuning & Behavior
*   **Default Value:** 0.
*   **Usage:** Usually handled by the `-j` flag in `sim_vehicle.py`, but can be manually configured here.