---
layout: parameter
name: H_RSC_GOV_DROOP
display_name: Governor Droop Compensator
description: AutoThrottle governor droop response under load. Higher value is quicker response to large speed changes.
default_value: 25
range: 0 100
units: %
group: H
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Motors/AP_MotorsHeli_RSC.cpp
---

# Governor Droop Compensator (H_RSC_GOV_DROOP)

## Description
Controls how aggressively the governor increases throttle when a drop in rotor RPM is detected due to increased load (e.g., during a climb).