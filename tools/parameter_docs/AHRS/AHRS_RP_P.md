---
layout: parameter
name: AHRS_RP_P
display_name: AHRS RP_P
description: This controls how fast the accelerometers correct the attitude.
default_value: 0.2
range: 0.1 0.4
units: 
group: AHRS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_AHRS/AP_AHRS.cpp
---

# AHRS RP_P (AHRS_RP_P)

## Description
Proportional gain for roll and pitch attitude correction using accelerometer data.

## Tuning & Behavior
*   **Default Value:** 0.2
*   **Range:** 0.1 to 0.4
*   **Higher values correct tilt errors faster but are more sensitive to vibration.**
