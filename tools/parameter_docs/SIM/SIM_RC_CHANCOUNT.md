---
layout: parameter
name: SIM_RC_CHANCOUNT
display_name: Simulated RC Channel Count
description: The number of RC input channels available in the simulator.
default_value: 16
range: 1 32
units: 
group: SIM
visual_asset_id: rc_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated RC Channel Count (SIM_RC_CHANCOUNT)

## Description
`SIM_RC_CHANCOUNT` sets the capacity of the virtual radio receiver.

## Tuning & Behavior
*   **Default Value:** 16.
*   **Recommendation:** Keep at **16** for most standard setups. Use higher values (up to 32) for testing complex Lua scripts or multi-gimbal setups.