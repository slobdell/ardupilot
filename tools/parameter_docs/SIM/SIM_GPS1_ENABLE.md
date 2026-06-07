---
layout: parameter
name: SIM_GPS1_ENABLE
display_name: Simulated GPS 1 Enable
description: Enables or disables the primary simulated GPS.
default_value: 1
range: 0 1
units: 
group: SIM
visual_asset_id: sim_gps_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated GPS 1 Enable (SIM_GPS1_ENABLE)

## Description
`SIM_GPS1_ENABLE` is the power switch for the virtual GPS. 

If you want to test how your drone flies with ONLY the secondary GPS, or no GPS at all, you can use this parameter to turn off the primary unit.

## Tuning & Behavior
*   **Default Value:** 1 (Enabled).
*   **0:** Disabled.