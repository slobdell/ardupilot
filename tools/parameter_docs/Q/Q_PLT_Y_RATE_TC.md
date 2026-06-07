---
layout: parameter
name: Q_PLT_Y_RATE_TC
display_name: Pilot Yaw Rate Time Constant
description: Time constant (in seconds) used to filter the pilot's yaw rate command.
default_value: 0.25
range: 0 1
units: s
group: Q
visual_asset_id: vtol_control_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# Pilot Yaw Rate Time Constant (Q_PLT_Y_RATE_TC)

## Description
`Q_PLT_Y_RATE_TC` determines how quickly the drone reaches the commanded yaw speed.

It smooths out the "Start" and "Stop" of a rotation. A higher value makes the drone feel heavier and more graceful, while a lower value makes it feel more responsive and robotic.

## Tuning & Behavior
*   **Default Value:** 0.25 seconds.