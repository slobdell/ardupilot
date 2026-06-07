---
layout: parameter
name: SIM_BARO_COUNT
display_name: Simulated Barometer Count
description: The number of simulated barometers to instantiate in the SITL environment.
default_value: 1
range: 1 3
units: 
group: SIM
visual_asset_id: sim_failure_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated Barometer Count (SIM_BARO_COUNT)

## Description
`SIM_BARO_COUNT` defines how many virtual atmospheric pressure sensors are available to the autopilot.

By increasing this to **2 or 3**, you can test ArduPilot's multi-baro redundancy and health monitoring. You can then use other `SIM_BARx_...` parameters to fail one sensor and watch the EKF switch to the backup.

## Tuning & Behavior
*   **Default Value:** 1.
*   **Recommendation:** Set to **2** for a realistic simulation of standard flight controller hardware (which often has two baros).
*   **Reboot Required:** Yes.