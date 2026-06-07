---
layout: parameter
name: SIM_FTOWESC_POW
display_name: Simulated TOWESC Power
description: The power rating (in Watts) for the simulated TOWESC motor model.
default_value: 0
range: 0 10000
units: W
group: SIM
visual_asset_id: sim_esc_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated TOWESC Power (SIM_FTOWESC_POW)

## Description
`SIM_FTOWESC_POW` defines the maximum power capacity of the heavy-lift motor simulation.