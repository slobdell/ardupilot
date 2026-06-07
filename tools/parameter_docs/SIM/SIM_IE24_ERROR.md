---
layout: parameter
name: SIM_IE24_ERROR
display_name: Simulated IE24 Error Code
description: Injects a specific error code into the simulated fuel cell telemetry.
default_value: 0
range: 0 4294967295
units: 
group: SIM
visual_asset_id: batt_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SIM_IntelligentEnergy24.cpp#L25
---

# Simulated IE24 Error Code (SIM_IE24_ERROR)

## Description
`SIM_IE24_ERROR` simulates a hardware failure.

By setting this to a valid IE24 error bitmask, you can verify that the GCS displays the correct warning message (e.g. "Low Hydrogen Pressure" or "Stack Over-temp").

## Tuning & Behavior
*   **Default Value:** 0.