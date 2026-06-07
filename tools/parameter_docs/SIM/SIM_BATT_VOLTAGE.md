---
layout: parameter
name: SIM_BATT_VOLTAGE
display_name: Simulation Battery Voltage
description: The starting battery voltage (in Volts) for the simulation.
default_value: 12.6
range: 0 100
units: V
group: SIM
visual_asset_id: batt_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L125
---

# Simulation Battery Voltage (SIM_BATT_VOLTAGE)

## Description
`SIM_BATT_VOLTAGE` sets the initial charge state.

## Tuning & Behavior
*   **Default Value:** 12.6 V (3S Lipo).
*   **Testing:** Set to **10.5** to test Battery Failsafe trigger on boot or takeoff.