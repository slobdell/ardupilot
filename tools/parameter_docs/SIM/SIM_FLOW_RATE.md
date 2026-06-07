---
layout: parameter
name: SIM_FLOW_RATE
display_name: Simulated Optical Flow Rate
description: The rate (in Hz) at which the simulated optical flow sensor generates data.
default_value: 10
range: 1 50
units: Hz
group: SIM
visual_asset_id: sim_flow_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated Optical Flow Rate (SIM_FLOW_RATE)

## Description
`SIM_FLOW_RATE` sets the data frequency of the virtual flow sensor.

## Tuning & Behavior
*   **Default Value:** 10 Hz.
*   **Recommendation:** Match your hardware specs (e.g., 50Hz for high-end sensors).