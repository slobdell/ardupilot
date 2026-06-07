---
layout: parameter
name: SOAR_Q2
display_name: Soaring EKF Position Noise
description: The process noise (uncertainty) for the estimated thermal center location.
default_value: 0.001
range: 0.0001 0.01
units: 
group: SOAR
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Soaring/AP_Soaring.cpp#L41
---

# Soaring EKF Position Noise (SOAR_Q2)

## Description
`SOAR_Q2` defines how much the autopilot expects the center of a thermal to "drift" or move.