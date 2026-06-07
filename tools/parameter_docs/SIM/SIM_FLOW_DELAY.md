---
layout: parameter
name: SIM_FLOW_DELAY
display_name: Simulated Optical Flow Delay
description: The delay (in milliseconds) added to the simulated optical flow data.
default_value: 0
range: 0 500
units: ms
group: SIM
visual_asset_id: sim_lag_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated Optical Flow Delay (SIM_FLOW_DELAY)

## Description
`SIM_FLOW_DELAY` simulates the processing lag of a smart camera (like HereFlow or PX4Flow).

## Tuning & Behavior
*   **Default Value:** 0 ms.
*   **Recommendation:** Set to **20** to match real hardware.