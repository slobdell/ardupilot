---
layout: parameter
name: SIM_WIND_DIR_Z
display_name: Simulated Vertical Wind Direction
description: The vertical direction of the wind (in degrees). 0 is horizontal, 90 is pure updraft.
default_value: 0
range: -90 90
units: deg
group: SIM
visual_asset_id: sim_wind_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated Vertical Wind Direction (SIM_WIND_DIR_Z)

## Description
`SIM_WIND_DIR_Z` simulates "Thermals" or "Downbursts."

*   **0:** Horizontal wind only.
*   **90:** Vertical updraft.
*   **-90:** Vertical downdraft.

## Tuning & Behavior
*   **Default Value:** 0.
*   **Testing:** Set to **10 or 20** to test your drone's altitude hold against a constant thermal rise.