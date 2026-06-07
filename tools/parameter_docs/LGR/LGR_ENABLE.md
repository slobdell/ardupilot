---
layout: parameter
name: LGR_ENABLE
display_name: Landing Gear Enable
description: Enables the retractable landing gear control system.
default_value: 0
range: 0 1
units: 
group: LGR
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_LandingGear/AP_LandingGear.cpp#L30
---

# Landing Gear Enable (LGR_ENABLE)

## Description
`LGR_ENABLE` activates the logic for controlling retractable landing gear.

When enabled, you can control the gear manually via an auxiliary switch or allow the autopilot to handle it automatically during takeoff and landing.

*   **1: Enabled.** Enables landing gear logic and makes other LGR parameters visible.
*   **0: Disabled.** Landing gear system is inactive.

## Tuning & Behavior
*   **Default:** 0.
*   **Setup:** You must also assign a motor output to the landing gear function by setting `SERVOx_FUNCTION = 29`.