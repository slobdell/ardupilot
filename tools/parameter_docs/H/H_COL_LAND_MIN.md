---
layout: parameter
name: H_COL_LAND_MIN
display_name: Collective Pitch Minimum when Landed
description: Minimum collective blade pitch angle when landed in degrees for modes that use altitude hold.
default_value: -2
range: -5 0
units: deg
group: H
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Motors/AP_MotorsHeli.cpp
---

# Collective Pitch Minimum when Landed (H_COL_LAND_MIN)

## Description
Restricts the minimum collective pitch while the aircraft is detected as "Landed" in automated modes (like AltHold). This prevents the aircraft from being forced onto the ground with excessive negative pitch.