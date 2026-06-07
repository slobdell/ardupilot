---
layout: parameter
name: AROT_HS_SENSOR
display_name: Main Rotor RPM Sensor
description: Allocate the RPM sensor instance to use for measuring head speed. RPM1 = 0, RPM2 = 1.
default_value: 0
range: 0 1
units: 
group: AROT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AC_Autorotation/AC_Autorotation.cpp
---

# Main Rotor RPM Sensor (AROT_HS_SENSOR)

## Description
Selects which RPM sensor instance provides the head speed feedback for the autorotation controller.

## Tuning & Behavior
*   **Default Value:** 0 (RPM1)
*   **Range:** 0 to 1