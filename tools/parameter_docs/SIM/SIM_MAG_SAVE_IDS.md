---
layout: parameter
name: SIM_MAG_SAVE_IDS
display_name: Simulated Magnetometer Save IDs
description: Controls whether the simulated magnetometer Device IDs are saved to parameters.
default_value: 0
range: 0 1
units: 
group: SIM
visual_asset_id: imu_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated Magnetometer Save IDs (SIM_MAG_SAVE_IDS)

## Description
`SIM_MAG_SAVE_IDS` makes the virtual compasses persistent.

Normally, every time you restart SITL, it generates new random "Device IDs" for the sensors. This forces you to re-calibrate the compass every time. If you enable this, the simulator saves the IDs, allowing you to keep your calibration data.

## Tuning & Behavior
*   **0:** Disabled (New IDs on boot).
*   **1:** Enabled (Save IDs).