---
layout: parameter
name: BARO1_WCF_LFT
display_name: Baro Wind Compensation Left (Sensor 1)
description: Coefficient to correct barometer errors caused by leftward airflow.
default_value: 0
range: -1.0 1.0
units: 
group: BARO
visual_asset_id: baro_wind_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Baro/AP_Baro_Wind.cpp#L26
---

# Baro Wind Compensation Left (BARO1_WCF_LFT)

## Description
`BARO1_WCF_LFT` compensates for pressure errors during leftward (sideways) flight. See [BARO1_WCF_FWD](BARO1_WCF_FWD.html) for more details.