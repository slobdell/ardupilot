---
layout: parameter
name: SIM_MAG_RND
display_name: Simulated Magnetometer Noise
description: The magnitude of random noise (in Gauss) added to the simulated magnetometer data.
default_value: 0
range: 0 1
units: Gauss
group: SIM
visual_asset_id: sim_noise_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated Magnetometer Noise (SIM_MAG_RND)

## Description
`SIM_MAG_RND` adds static fuzz to the compass readings.

## Tuning & Behavior
*   **Default Value:** 0.
*   **Testing:** Increase this to see how much noise the EKF can tolerate before triggering a "Compass Variance" error.