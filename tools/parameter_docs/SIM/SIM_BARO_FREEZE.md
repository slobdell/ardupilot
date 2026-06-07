---
layout: parameter
name: SIM_BARO_FREEZE
display_name: Simulated Barometer Freeze
description: Freezes the barometer output to its current value.
default_value: 0
range: 0 1
units: 
group: SIM
visual_asset_id: sim_failure_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated Barometer Freeze (SIM_BARO_FREEZE)

## Description
`SIM_BARO_FREEZE` locks the barometer value.

This simulates a sensor driver crash or a clogged static port. If the drone climbs or descends, the barometer will report 0 vertical speed.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled).
*   **1:** Freeze enabled.