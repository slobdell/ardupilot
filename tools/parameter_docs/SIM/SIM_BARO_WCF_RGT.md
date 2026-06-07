---
layout: parameter
name: SIM_BARO_WCF_RGT
display_name: Simulated Baro Wind Comp Factor Right
description: Pressure change due to wind from the right direction (Pascals per m/s^2).
default_value: 0
range: -10 10
units: Pa/(m/s)^2
group: SIM
visual_asset_id: sim_noise_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated Baro Wind Comp Factor Right (SIM_BARO_WCF_RGT)

## Description
Defines pressure change due to wind from the right. See `SIM_BARO_WCF_UP`.