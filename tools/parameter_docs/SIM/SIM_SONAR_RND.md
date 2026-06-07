---
layout: parameter
name: SIM_SONAR_RND
display_name: Simulated Sonar Noise
description: The amount of noise (in meters) added to the simulated sonar distance.
default_value: 0
range: 0 5
units: m
group: SIM
visual_asset_id: sim_noise_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated Sonar Noise (SIM_SONAR_RND)

## Description
`SIM_SONAR_RND` adds Gaussian noise to the rangefinder distance.

## Tuning & Behavior
*   **Default Value:** 0 m.
*   **Recommendation:** Set to **0.05** (5cm) for realistic testing.