---
layout: parameter
name: LGR_DEPLOY_PIN
display_name: Chassis deployment feedback pin
description: Pin number to use for detection of gear deployment. If set to -1, feedback is disabled.
default_value: -1
range: 
units: 
group: LGR
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_LandingGear/AP_LandingGear.cpp#L45
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_LandingGear/AP_LandingGear.h#L93
---

# LGR_DEPLOY_PIN: Chassis deployment feedback pin

## Description
Pin number to use for detection of gear deployment. If set to -1, feedback is disabled.

## Values
- **Range:** -1 to 55 (GPIO Pin Number)
- **Default:** -1 (Disabled)

## Description
This parameter assigns a GPIO (General Purpose Input/Output) pin to read a limit switch or sensor that detects when the landing gear is fully deployed (down and locked).

- **Usage:** Connect a microswitch or hall sensor to this pin.
- **Function:** When the pin enters the state defined by `LGR_DEPLOY_POL`, the autopilot confirms the gear is down. This can be used to prevent landing if the gear fails to deploy.

## Source Code
[ardupilot/libraries/AP_LandingGear/AP_LandingGear.cpp](https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_LandingGear/AP_LandingGear.cpp#L45)

