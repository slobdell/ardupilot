---
layout: parameter
name: SIM_FLOW_ENABLE
display_name: Simulated Optical Flow Enable
description: Enables the simulated Optical Flow sensor.
default_value: 0
range: 0 1
units: 
group: SIM
visual_asset_id: sim_flow_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated Optical Flow Enable (SIM_FLOW_ENABLE)

## Description
`SIM_FLOW_ENABLE` adds a virtual Optical Flow camera to the drone.

This allows you to test non-GPS loiter modes (`FlowHold`) and indoor navigation logic.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled).
*   **1:** Enabled.