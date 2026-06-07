---
layout: parameter
name: BARO1_WCF_RGT
display_name: Baro Wind Compensation Right (Sensor 1)
description: Coefficient to correct barometer errors caused by rightward airflow.
default_value: 0
range: -1.0 1.0
units: 
group: BARO
visual_asset_id: baro_wind_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Baro/AP_Baro_Wind.cpp#L28
---

# Baro Wind Compensation Right (BARO1_WCF_RGT)

## Description
`BARO1_WCF_RGT` compensates for pressure errors during rightward (sideways) flight. See [BARO1_WCF_FWD](BARO1_WCF_FWD.html) for more details.