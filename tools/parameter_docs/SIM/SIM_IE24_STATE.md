---
layout: parameter
name: SIM_IE24_STATE
display_name: Simulated IE24 State
description: Manually sets the internal state of the simulated fuel cell.
default_value: 0
range: 0 10
units: 
group: SIM
visual_asset_id: batt_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SIM_IntelligentEnergy24.cpp#L25
---

# Simulated IE24 State (SIM_IE24_STATE)

## Description
`SIM_IE24_STATE` overrides the fuel cell logic.

*   **0:** Auto (Normal operation).
*   **1:** Starting.
*   **2:** Running.
*   **4:** Fault.

## Tuning & Behavior
*   **Default Value:** 0.