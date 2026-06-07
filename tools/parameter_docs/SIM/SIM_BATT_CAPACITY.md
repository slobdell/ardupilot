---
layout: parameter
name: SIM_BATT_CAPACITY
display_name: Simulation Battery Capacity
description: The total capacity (in mAh) of the simulated battery.
default_value: 10000
range: 0 50000
units: mAh
group: SIM
visual_asset_id: batt_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L126
---

# Simulation Battery Capacity (SIM_BATT_CAPACITY)

## Description
`SIM_BATT_CAPACITY` defines the size of the virtual fuel tank.

SITL calculates current draw based on motor thrust. This parameter allows you to test battery failsafe logic by simulating a realistic discharge curve.

## Tuning & Behavior
*   **Default Value:** 10000 mAh.
*   **Testing:** Set to a small value (e.g. 500) to quickly trigger a "Low Battery" failsafe during a test flight.
