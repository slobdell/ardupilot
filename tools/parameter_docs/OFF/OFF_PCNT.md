---
layout: parameter
title: OFF_PCNT
name: Maximum offset cal speed error
group: OFF
---

# OFF_PCNT: Maximum offset cal speed error

## Description
The maximum percentage speed change in airspeed reports that is allowed due to offset changes between calibrations before a warning is issued. This potential speed error is in percent of `AIRSPEED_MIN`.

## Values
- **Range:** 0.0 to 10.0
- **Units:** %
- **Default:** 0

## Description
This parameter is a safety check for airspeed sensor calibration.

- **Purpose:** It checks if a new calibration offset differs significantly from the previous one, which might indicate the pitot tube was uncovered during calibration (wind affecting the reading) or a sensor fault.
- **Mechanism:** If the new offset would cause a reported speed change greater than this percentage (relative to `AIRSPEED_MIN`), a warning is issued: "Arspd offset change large; cover and recal".
- **0:** Disabled.

## Source Code
[ardupilot/libraries/AP_Airspeed/AP_Airspeed.cpp](https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Airspeed/AP_Airspeed.cpp#L164)

