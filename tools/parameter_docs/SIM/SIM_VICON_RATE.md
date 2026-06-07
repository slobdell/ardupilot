---
layout: parameter
name: SIM_VICON_RATE
display_name: Simulated Vicon Update Rate
description: The frequency (in Hz) at which simulated Vicon/Motion Capture data is sent to the autopilot.
default_value: 50
range: 1 200
units: Hz
group: SIM
visual_asset_id: sim_vicon_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated Vicon Update Rate (SIM_VICON_RATE)

## Description
`SIM_VICON_RATE` sets the data frequency of the virtual motion capture system.

Standard Vicon systems run at 50Hz to 100Hz. A higher rate provides a smoother position estimate for the EKF, while a lower rate tests how the autopilot handles sparse tracking data.

## Tuning & Behavior
*   **Default Value:** 50 Hz.
*   **Recommendation:** Set to **100** for ultra-stable indoor loiter testing.