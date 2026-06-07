---
layout: parameter
name: LGR_OPTIONS
display_name: Landing Gear Options
description: Bitmask for automated landing gear behaviors (Auto-Retract, Auto-Deploy).
default_value: 3
range: 0 3
units: Bitmask
group: LGR
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_LandingGear/AP_LandingGear.cpp#L93
---

# Landing Gear Options (LGR_OPTIONS)

## Description
`LGR_OPTIONS` defines when the autopilot should move the landing gear without pilot intervention.

*   **Bit 0 (1): Retract after Takeoff.** Automatically pulls the gear up once a safe climb is established.
*   **Bit 1 (2): Deploy during Land.** Automatically lowers the gear when the aircraft begins its final approach or reaches a specific altitude.

## Tuning & Behavior
*   **Default:** 3 (Both Auto-Retract and Auto-Deploy enabled).
*   **Altitude Trigger:** Use [LGR_DEPLOY_ALT](LGR_DEPLOY_ALT.html) and [LGR_RETRACT_ALT](LGR_RETRACT_ALT.html) to fine-tune exactly when these actions occur.