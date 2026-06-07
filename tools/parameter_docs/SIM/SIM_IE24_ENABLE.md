---
layout: parameter
name: SIM_IE24_ENABLE
display_name: Simulated IE24 Fuel Cell Enable
description: Enables the simulated Intelligent Energy 2.4kW Fuel Cell.
default_value: 0
range: 0 1
units: 
group: SIM
visual_asset_id: batt_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SIM_IntelligentEnergy24.cpp#L25
---

# Simulated IE24 Fuel Cell Enable (SIM_IE24_ENABLE)

## Description
`SIM_IE24_ENABLE` adds a virtual Hydrogen Fuel Cell to the simulation.

This allows you to test the telemetry feedback (tank pressure, stack voltage, error states) of an Intelligent Energy 2.4kW unit without needing the expensive hardware.

## Tuning & Behavior
*   **0:** Disabled.
*   **1:** Enabled.