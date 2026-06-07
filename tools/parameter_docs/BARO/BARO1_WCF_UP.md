---
layout: parameter
name: BARO1_WCF_UP
display_name: Baro Wind Compensation Up (Sensor 1)
description: Coefficient to correct barometer errors caused by upward airflow.
default_value: 0
range: -1.0 1.0
units: 
group: BARO
visual_asset_id: baro_wind_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Baro/AP_Baro_Wind.cpp#L30
---

# Baro Wind Compensation Up (BARO1_WCF_UP)

## Description
`BARO1_WCF_UP` compensates for pressure errors during upward (vertical) flight. See [BARO1_WCF_FWD](BARO1_WCF_FWD.html) for more details.