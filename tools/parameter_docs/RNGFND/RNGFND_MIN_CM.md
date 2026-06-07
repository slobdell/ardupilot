---
layout: parameter
name: RNGFND_MIN_CM
display_name: Rangefinder minimum distance
description: Minimum distance in centimeters that rangefinder can reliably read.
default_value: 20
range: 
units: cm
group: RNGFND
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_RangeFinder/AP_RangeFinder_Params.cpp#L58
---

# RNGFND_MIN_CM: Rangefinder minimum distance

## Description
Minimum distance in centimeters that rangefinder can reliably read.

## Values
- **Units:** cm
- **Increment:** 1
- **Default:** 20

## Description
This parameter defines the "Blind Spot" of your rangefinder.

- **Function:** Any distance reading reported by the sensor that is *less* than this value will be ignored by the autopilot and treated as "Out of Range."
- **Why it matters:** Most Sonar and Lidar sensors have a physical limit where they cannot distinguish between zero distance and a very close object. If this value is set too low, the drone might think it is at ground level while still several inches in the air, leading to a premature motor cut or a hard landing.

