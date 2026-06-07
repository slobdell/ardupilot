---
layout: parameter
title: LGR_RETRACT_ALT
name: Landing gear retract altitude
group: LGR
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_LandingGear/AP_LandingGear.cpp#L85
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_LandingGear/AP_LandingGear.h#L98
---

# LGR_RETRACT_ALT: Landing gear retract altitude

## Description
Altitude where the landing gear will be retracted. This should be higher than the `LGR_DEPLOY_ALT`. If zero, altitude is not used for retracting landing gear. Only applies when the vehicle is armed.

## Values
- **Range:** 0 to 1000
- **Units:** m
- **Increment:** 1
- **Default:** 0

## Description
This parameter automates landing gear retraction based on altitude.

- **Function:** When the vehicle climbs above this altitude (in meters above home), the landing gear will automatically retract.
- **Usage:** Set this to a safe height (e.g., 10-20 meters) to automatically clean up the airframe after takeoff.
- **Constraint:** Must be higher than `LGR_DEPLOY_ALT` to prevent rapid toggling.

## Source Code
[ardupilot/libraries/AP_LandingGear/AP_LandingGear.cpp](https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_LandingGear/AP_LandingGear.cpp#L85)

