---
layout: parameter
name: ARSPD_WIND_GATE
display_name: Re-enable Consistency Check Gate Size
description: Number of standard deviations applied to the re-enable EKF consistency check that is used when ARSPD_OPTIONS bit position 3 is set.
default_value: 5.0
range: 0.0 10.0
units: 
group: ARSPD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Airspeed/AP_Airspeed.cpp
---

# Re-enable Consistency Check Gate Size (ARSPD_WIND_GATE)

## Description
Sensitivity of the logic that re-enables a previously failed airspeed sensor once its readings return to a statistically consistent range.

## Tuning & Behavior
*   **Default Value:** 5.0
*   **Range:** 0.0 to 10.0
*   **Higher values make re-enabling easier but carry higher risk of using bad data.**