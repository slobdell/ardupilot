---
layout: parameter
name: SIM_SHOVE_X
display_name: Simulated Shove X
description: A velocity impulse (in m/s) applied to the vehicle in the Body-Frame X axis.
default_value: 0
range: -30 30
units: m/s
group: SIM
visual_asset_id: sim_physics_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated Shove X (SIM_SHOVE_X)

## Description
`SIM_SHOVE_X` kicks the drone forward or backward.

When you change this parameter (e.g. via MAVProxy), the simulator instantly adds this velocity to the vehicle's state. It is used to test the position controller's ability to recover from a sudden disturbance.

## Tuning & Behavior
*   **Default Value:** 0.
*   **Usage:** Set to **5** to simulate being hit by a 5 m/s gust or object from behind.