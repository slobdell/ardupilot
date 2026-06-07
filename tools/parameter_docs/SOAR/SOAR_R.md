---
layout: parameter
name: SOAR_R
display_name: Soaring EKF Measurement Noise
description: The measurement noise (uncertainty) for the variometer data.
default_value: 0.1
range: 0.01 1.0
units: 
group: SOAR
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Soaring/AP_Soaring.cpp#L48
---

# Soaring EKF Measurement Noise (SOAR_R)

## Description
`SOAR_R` defines how much the autopilot "Trusts" the data coming from your Variometer/Barometer.