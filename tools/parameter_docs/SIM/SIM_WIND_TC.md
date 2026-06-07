---
layout: parameter
name: SIM_WIND_TC
display_name: Simulated Wind Time Constant
description: The time (in seconds) over which wind changes take effect.
default_value: 5
range: 1 100
units: s
group: SIM
visual_asset_id: sim_wind_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated Wind Time Constant (SIM_WIND_TC)

## Description
`SIM_WIND_TC` controls how quickly the wind "Wanders" between different speeds and directions. 

A small value means the wind changes instantly (very gusty). A large value means the wind changes slowly and smoothly over several seconds.

## Tuning & Behavior
*   **Default Value:** 5 seconds.
*   **Recommendation:** Leave at **5** for realistic atmospheric behavior.