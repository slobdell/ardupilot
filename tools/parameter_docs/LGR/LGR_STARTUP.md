---
layout: parameter
name: LGR_STARTUP
display_name: Landing Gear Startup Position
description: Defines the initial state of the landing gear when the autopilot is powered on.
default_value: 0
range: 0 2
units: 
group: LGR
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_LandingGear/AP_LandingGear.cpp#L37
---

# Landing Gear Startup Position (LGR_STARTUP)

## Description
`LGR_STARTUP` determines the physical position of the landing gear immediately after the flight controller boots up.

This is a safety-critical setting. If the gear defaults to "Retracted" while the drone is sitting on the ground, it could cause damage to the gimbal or airframe.

*   **0: WaitForPilotInput (Default).** The gear stays exactly where it was until the pilot flips the gear switch on the transmitter.
*   **1: Retract.** The gear will immediately attempt to pull up upon power-on. (Not recommended for ground starts!)
*   **2: Deploy.** The gear will immediately attempt to extend upon power-on.

## Tuning & Behavior
*   **Recommendation:** Use **0 (Wait for Input)** or **2 (Deploy)** for most multirotors.