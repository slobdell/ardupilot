---
layout: parameter
name: LGR_DEPLOY_POL
display_name: Landing Gear Deployment Polarity
description: Sets whether the gear is deployed on a HIGH or LOW signal.
default_value: 0
range: 0 1
units: 
group: LGR
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_LandingGear/AP_LandingGear.cpp#L40
---

# Landing Gear Deployment Polarity (LGR_DEPLOY_POL)

## Description
`LGR_DEPLOY_POL` defines the logic of the landing gear deployment signal.

*   **0: Normal.** 
*   **1: Inverted.** 

## Tuning & Behavior
*   **Usage:** If your landing gear retracts when it should deploy (and vice versa), toggle this parameter. This is often necessary when using different brands of electronic retracts.