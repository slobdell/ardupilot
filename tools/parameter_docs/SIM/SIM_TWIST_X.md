---
layout: parameter
name: SIM_TWIST_X
display_name: Simulated Twist X
description: An angular velocity impulse (in deg/s) applied to the vehicle around the Body-Frame X axis (Roll).
default_value: 0
range: -360 360
units: deg/s
group: SIM
visual_asset_id: sim_physics_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated Twist X (SIM_TWIST_X)

## Description
`SIM_TWIST_X` spins the drone in Roll.

Use this to test the attitude controller's ability to stop a roll tumble.

## Tuning & Behavior
*   **Default Value:** 0.