---
layout: parameter
name: SIM_FLOW_RND
display_name: Simulated Optical Flow Noise
description: The amount of noise (in rad/s) added to the simulated optical flow angular rates.
default_value: 0.05
range: 0 0.5
units: rad/s
group: SIM
visual_asset_id: sim_noise_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated Optical Flow Noise (SIM_FLOW_RND)

## Description
`SIM_FLOW_RND` simulates the "jitter" of an optical flow sensor looking at a difficult surface (like grass or carpet).

## Tuning & Behavior
*   **Default Value:** 0.05 rad/s.
*   **Recommendation:** Increase to **0.2** to test if your drone can hold position over low-contrast surfaces.