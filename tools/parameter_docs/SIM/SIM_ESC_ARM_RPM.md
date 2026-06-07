---
layout: parameter
name: SIM_ESC_ARM_RPM
display_name: Simulated ESC Armed RPM
description: The RPM value reported by the simulated ESCs when the motors are armed at minimum throttle.
default_value: 0
range: 0 5000
units: RPM
group: SIM
visual_asset_id: sim_esc_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated ESC Armed RPM (SIM_ESC_ARM_RPM)

## Description
`SIM_ESC_ARM_RPM` sets the "Idle Speed" for the virtual RPM feedback.

## Tuning & Behavior
*   **Default Value:** 0.
*   **Recommendation:** Set to **500 or 1000** to simulate the low-end spinning of motors while the drone is on the ground but armed.