---
layout: parameter
name: ARMING_MAGTHRESH
display_name: Compass magnetic field strength error threshold
description: Compass magnetic field strength error threshold vs earth magnetic model. X and y axis are compared using this threshold, Z axis uses 2x this threshold. 0 to disable check.
default_value: 100
range: 0 500
units: mGauss
group: ARMING
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Arming/AP_Arming.cpp
---

# Compass magnetic field strength error threshold (ARMING_MAGTHRESH)

## Description
Maximum allowable deviation of the measured magnetic field from the expected Earth magnetic model (based on GPS location).

## Tuning & Behavior
*   **Default Value:** 100 mGauss
*   **Range:** 0 to 500 mGauss
*   **Ensures the compass is properly calibrated and not affected by local interference.**
