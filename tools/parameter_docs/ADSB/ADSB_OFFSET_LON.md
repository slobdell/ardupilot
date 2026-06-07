---
layout: parameter
name: ADSB_OFFSET_LON
display_name: GPS antenna longitudinal offset
description: GPS antenna longitudinal offset. This is usually set to 1, Applied By Sensor.
default_value: 1
range: 
units: 
group: ADSB
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_ADSB/AP_ADSB.cpp
---

# GPS antenna longitudinal offset (ADSB_OFFSET_LON)

## Description
Physical location offset along the longitudinal axis of the GPS antenna.

## Tuning & Behavior
*   **Default Value:** 1 (AppliedBySensor)
*   **Values:** 0:NO_DATA, 1:AppliedBySensor