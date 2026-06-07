---
layout: parameter
name: SIM_INS_THR_MIN
display_name: Simulated INS Noise Throttle Min
description: The minimum throttle level above which motor-induced noise is added to the simulated IMUs.
default_value: 0.1
range: 0 1
units: '%'
group: SIM
visual_asset_id: sim_noise_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated INS Noise Throttle Min (SIM_INS_THR_MIN)

## Description
`SIM_INS_THR_MIN` defines when the "Shaking" starts.

Real drones vibrate more when the motors are spinning fast. This parameter tells SITL to only add motor-induced noise when the throttle is above a certain percentage (e.g. 10%). On the ground at zero throttle, the IMUs will remain clean.

## Tuning & Behavior
*   **Default Value:** 0.1 (10% throttle).