---
layout: parameter
name: H_RSC_GOV_RANGE
display_name: Governor Operational Range
description: RPM range +/- governor rpm reference setting where the governor is operational.
default_value: 100
range: 50 200
units: RPM
group: H
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Motors/AP_MotorsHeli_RSC.cpp
---

# Governor Operational Range (H_RSC_GOV_RANGE)

## Description
Defines the safety window for the internal governor. If the measured RPM deviates from the target by more than this amount, the governor will automatically disengage and fall back to the throttle curve.
