---
layout: parameter
name: SIM_CLAMP_CH
display_name: Simulated Clamp Channel
description: An RC channel that, when high, clamps the vehicle to the ground.
default_value: 0
range: 0 16
units: 
group: SIM
visual_asset_id: sim_physics_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated Clamp Channel (SIM_CLAMP_CH)

## Description
`SIM_CLAMP_CH` creates a virtual "Mag-Lock" on the landing gear.

When the selected RC channel is High (PWM > 1800), the drone is physically stuck to the ground, regardless of throttle. This is useful for testing "Ground Idle" vibration or tuning PID loops without the drone taking off.

## Tuning & Behavior
*   **0:** Disabled.
*   **1-16:** RC Channel number.