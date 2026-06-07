---
layout: parameter
name: SIM_MAG_NOISE
display_name: Simulated Magnetometer Noise
description: The amount of noise (in milliGauss) added to the simulated compass.
default_value: 0
range: 0 100
units: mGauss
group: SIM
visual_asset_id: sim_noise_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L140
---

# Simulated Magnetometer Noise (SIM_MAG_NOISE)

## Description
`SIM_MAG_NOISE` adds random jitter to the compass readings.

Real compasses are very clean sensors, but they are affected by surrounding electronics. This parameter simulates that background electromagnetic noise.

## Tuning & Behavior
*   **Default Value:** 0.
*   **Recommendation:** Set to **5-10 mGauss** for realistic testing.
