---
layout: parameter
name: SIM_ARSPD_PITOT
display_name: Simulated Pitot Blockage Pressure
description: The pressure (in Pascals) to report when the pitot tube is blocked.
default_value: 0
range: 0 1000
units: Pa
group: SIM
visual_asset_id: sim_failure_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L1250
---

# Simulated Pitot Blockage Pressure (SIM_ARSPD_PITOT)

## Description
`SIM_ARSPD_PITOT` simulates a blocked pitot tube (e.g., mud wasp nest).

If you set `SIM_ARSPD_FAIL` to enable failure, this is the pressure value the sensor will output.

## Tuning & Behavior
*   **Default Value:** 0 Pa.