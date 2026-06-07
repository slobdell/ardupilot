---
layout: parameter
name: SIM_VIB_MOT_MASK
display_name: Simulated Motor Vibration Mask
description: A bitmask of motors that generate simulated vibration noise.
default_value: 0
range: 0 4294967295
units: 
group: SIM
visual_asset_id: sim_noise_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated Motor Vibration Mask (SIM_VIB_MOT_MASK)

## Description
`SIM_VIB_MOT_MASK` selects which virtual motors are "Noisy."

By default (0), all motors contribute equally to vibration. By setting this bitmask, you can simulate a single motor with a damaged propeller to see how the EKF handles asymmetrical noise.

## Tuning & Behavior
*   **Default Value:** 0 (All motors).
*   **Bit 0 (1):** Motor 1 only.