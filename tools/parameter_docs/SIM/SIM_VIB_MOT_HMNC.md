---
layout: parameter
name: SIM_VIB_MOT_HMNC
display_name: Simulated Motor Harmonics
description: The number of harmonic vibration peaks to generate per simulated motor.
default_value: 1
range: 1 5
units: 
group: SIM
visual_asset_id: sim_noise_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated Motor Harmonics (SIM_VIB_MOT_HMNC)

## Description
`SIM_VIB_MOT_HMNC` simulates the "Overtones" of motor vibration.

In the real world, a motor doesn't just vibrate at its base frequency; it also creates noise at 2x, 3x, and 4x that frequency. This parameter tells SITL how many of these harmonics to simulate, allowing you to test if your `INS_HNTCH_HMNCS` bitmask is set correctly.

## Tuning & Behavior
*   **Default Value:** 1.
*   **Testing:** Set to **3** and verify your Harmonic Notch can clear all three spikes in an FFT graph.