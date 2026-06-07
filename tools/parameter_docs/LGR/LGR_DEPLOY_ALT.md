---
layout: parameter
title: LGR_DEPLOY_ALT
name: Landing gear deployment altitude
group: LGR
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_LandingGear/AP_LandingGear.cpp#L76
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_LandingGear/AP_LandingGear.h#L97
---

# LGR_DEPLOY_ALT: Landing gear deployment altitude

## Description
Altitude where the landing gear will be deployed. This should be lower than the `LGR_RETRACT_ALT`. If zero, altitude is not used for deploying landing gear. Only applies when the vehicle is armed.

## Values
- **Range:** 0 to 1000
- **Units:** m
- **Increment:** 1
- **Default:** 0

## Description
This parameter automates landing gear deployment based on altitude.

- **Function:** When the vehicle descends below this altitude (in meters above home), the landing gear will automatically deploy.
- **Safety:** Useful for ensuring gear is down for landing even if the pilot forgets.
- **Constraint:** Must be set lower than `LGR_RETRACT_ALT` (Retract Altitude) to prevent rapid toggling (hysteresis).

## Source Code
[ardupilot/libraries/AP_LandingGear/AP_LandingGear.cpp](https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_LandingGear/AP_LandingGear.cpp#L76)

