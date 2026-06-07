---
layout: parameter
name: SIM_BATT_CAP_AH
display_name: Simulated Battery Capacity
description: The total capacity (in Amp-hours) of the simulated battery.
default_value: 0
range: 0 1000
units: Ah
group: SIM
visual_asset_id: batt_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated Battery Capacity (SIM_BATT_CAP_AH)

## Description
`SIM_BATT_CAP_AH` defines how much "Fuel" the virtual battery has.

As you fly in SITL, the autopilot calculates current draw based on motor throttle. This parameter determines how fast the voltage drops. If set to 0, the battery is "Infinite" and will never drain.
