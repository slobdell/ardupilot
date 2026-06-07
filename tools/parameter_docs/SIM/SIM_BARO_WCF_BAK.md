---
layout: parameter
name: SIM_BARO_WCF_BAK
display_name: Simulation Barometer Wind Coefficient Backward
description: Simulates the pressure change (error) on the barometer caused by backward airspeed.
default_value: 0
range: -0.1 0.1
units: 
group: SIM
visual_asset_id: sim_physics_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL_Baro.cpp#L48
---

# Simulation Barometer Wind Coefficient Backward (SIM_BARO_WCF_BAK)

## Description
`SIM_BARO_WCF_BAK` simulates pressure errors when the drone is flying backwards.

See [SIM_BARO_WCF_FWD](SIM_BARO_WCF_FWD.html) for more details.
