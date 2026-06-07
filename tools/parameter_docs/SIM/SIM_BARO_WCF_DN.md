---
layout: parameter
name: SIM_BARO_WCF_DN
display_name: Simulation Baro Wind Coeff (Down)
description: The pressure error coefficient for the simulated barometer during a descent.
default_value: 0
range: -1.0 1.0
units: 
group: SIM
visual_asset_id: airspeed_pitot_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L110
---

# Simulation Baro Wind Coeff (SIM_BARO_WCF_DN)

## Description
`SIM_BARO_WCF_DN` simulates aerodynamic interference that makes the altitude reading glitch during a fast descent.

See [BARO1_WCF_ENABLE](../BARO1/BARO1_WCF_ENABLE.html) for details on the real-world compensation model. This parameter allows you to inject those same errors into SITL to test your compensation tuning.
