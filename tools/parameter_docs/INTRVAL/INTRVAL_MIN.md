---
layout: parameter
title: INTRVAL_MIN
name: Camera minimum time interval between photos
group: INTRVAL
---

# INTRVAL_MIN: Camera minimum time interval between photos

## Description
Postpone shooting if previous picture was taken less than this many seconds ago.

## Values
- **Range:** 0 to 10
- **Units:** s
- **Default:** 0

## Description
This parameter enforces a minimum "cooldown" period between camera triggers.

- **Purpose:** Useful for cameras that need time to save a photo to the SD card before taking another one. If the flight controller tries to trigger the camera faster than this rate (e.g., due to high speed and low `CAM_TRIGG_DIST`), the trigger command will be skipped or delayed until the interval has passed.
- **0:** Disabled (triggers as fast as commanded).

## Source Code
[ardupilot/libraries/AP_Camera/AP_Camera_Params.cpp](https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Camera/AP_Camera_Params.cpp#L60)

