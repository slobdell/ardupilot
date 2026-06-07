---
layout: parameter
name: SIM_PLD_ENABLE
display_name: Simulated Precision Landing Enable
description: Enables the simulated Precision Landing beacon/target.
default_value: 0
range: 0 1
units: 
group: SIM
visual_asset_id: plnd_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SIM_Precland.cpp#L25
---

# Simulated Precision Landing Enable (SIM_PLD_ENABLE)

## Description
`SIM_PLD_ENABLE` adds a virtual infrared beacon or visual target to the world.

This is the primary way to test "Precision Landing" (`PLND_ENABLE`) in the simulator. It simulates the data from an IR-Lock camera or a downward-facing visual system.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled).
*   **1:** Enabled. The target will spawn at the coordinates defined by `SIM_PLD_LAT/LON`.