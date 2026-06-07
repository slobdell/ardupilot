---
layout: parameter
name: ARSPD_OFF_PCNT
display_name: Maximum offset cal speed error
description: The maximum percentage speed change in airspeed reports that is allowed due to offset changes between calibrations before a warning is issued.
default_value: 0
range: 0.0 10.0
units: %
group: ARSPD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Airspeed/AP_Airspeed.cpp
---

# Maximum offset cal speed error (ARSPD_OFF_PCNT)

## Description
Safety threshold to detect if an airspeed calibration was performed incorrectly (e.g., pitot tube not covered).

## Tuning & Behavior
*   **Default Value:** 0 (Disabled)
*   **Range:** 0.0 to 10.0 %