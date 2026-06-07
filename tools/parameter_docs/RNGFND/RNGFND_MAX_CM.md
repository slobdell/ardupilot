---
layout: parameter
name: RNGFND_MAX_CM
display_name: Rangefinder maximum distance
description: Maximum distance in centimeters that rangefinder can reliably read.
default_value: 700
range: 
units: cm
group: RNGFND
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_RangeFinder/AP_RangeFinder_Params.cpp#L66
---

# RNGFND_MAX_CM: Rangefinder maximum distance

## Description
Maximum distance in centimeters that rangefinder can reliably read.

## Values
- **Units:** cm
- **Increment:** 1
- **Default:** 700

## Description
This parameter defines the "Range Limit" for the rangefinder.

- **Function:** Any reading above this value is ignored. If the sensor reports a value higher than this, ArduPilot treats it as "Out of Range" (e.g., looking into clear sky).
- **Usage:** Set this to slightly *less* than the maximum distance listed in your sensor's datasheet to ensure high reliability. If your sensor is rated for 10 meters, setting this to **900** (9m) can prevent the autopilot from acting on weak, noisy signals at the edge of the sensor's capability.
- **Altitude Limit:** If the drone flies higher than this altitude, the EKF will stop using the rangefinder for terrain following or precision landing and switch back to Barometer/GPS altitude.

