---
layout: parameter
name: BARO1_WCF_DN
display_name: Baro Wind Compensation Down (Sensor 1)
description: Coefficient to correct barometer errors caused by downward airflow.
default_value: 0
range: -1.0 1.0
units: 
group: BARO
visual_asset_id: baro_wind_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Baro/AP_Baro_Wind.cpp#L32
---

# Baro Wind Compensation Down (BARO1_WCF_DN)

## Description
`BARO1_WCF_DN` compensates for pressure errors during downward (vertical) flight. See [BARO1_WCF_FWD](BARO1_WCF_FWD.html) for more details.