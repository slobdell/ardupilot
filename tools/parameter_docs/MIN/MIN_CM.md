---
layout: parameter
name: MIN_CM
display_name: Rangefinder minimum distance
description: Minimum distance in centimeters that the rangefinder can reliably read.
default_value: 20
range: 
units: cm
group: MIN
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_RangeFinder/AP_RangeFinder_Params.cpp#L58
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_RangeFinder/AP_RangeFinder_Params.h#L23
---

# MIN_CM: Rangefinder minimum distance

## Description
Minimum distance in centimeters that the rangefinder can reliably read.

## Values
- **Units:** cm
- **Increment:** 1
- **Default:** 20

## Description
This parameter defines the "blind spot" of the rangefinder.

- **Function:** Any reading returned by the sensor that is less than this value will be treated as invalid (out of range).
- **Why it matters:** Most acoustic (Sonar) and optical (Lidar) rangefinders cannot measure distance zero. They have a minimum range (e.g., 20cm). If the vehicle is on the ground and the sensor reads noise below this threshold, filtering out these values prevents the autopilot from thinking it's flying underground or getting bad altitude data.

## Source Code
[ardupilot/libraries/AP_RangeFinder/AP_RangeFinder_Params.cpp](https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_RangeFinder/AP_RangeFinder_Params.cpp#L58)
