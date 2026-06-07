---
layout: parameter
name: SIM_BARO_GLITCH
display_name: Simulated Barometer Glitch
description: The magnitude of a sudden altitude offset (in meters) applied to the barometer.
default_value: 0
range: 0 100
units: m
group: SIM
visual_asset_id: sim_noise_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated Barometer Glitch (SIM_BARO_GLITCH)

## Description
`SIM_BARO_GLITCH` applies an instant step-change to the altitude reading.

This simulates events like opening a window in a pressurized room or a sudden pressure wave from a passing truck.

## Tuning & Behavior
*   **Default Value:** 0 m.
*   **Testing:** Set to **50** (meters) while hovering. Verify that the drone does NOT shoot up/down 50 meters instantly. The EKF should reject the jump or smooth it out.