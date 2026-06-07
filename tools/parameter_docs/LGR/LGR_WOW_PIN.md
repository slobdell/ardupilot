---
layout: parameter
name: LGR_WOW_PIN
display_name: Weight on Wheels (WOW) Feedback Pin
description: The physical GPIO pin connected to a limit switch that detects when the vehicle is on the ground.
default_value: -1
range: -1 103
units: 
group: LGR
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_LandingGear/AP_LandingGear.cpp#L60
---

# Weight on Wheels (WOW) Feedback Pin (LGR_WOW_PIN)

## Description
`LGR_WOW_PIN` tells the autopilot if the drone is physically sitting on its landing gear.

This requires a physical switch or sensor (Weight-on-Wheels / WOW) mounted on the landing gear strut. When the gear is compressed by the weight of the aircraft, the switch triggers. This provides a high-certainty "On Ground" signal that the autopilot can use for safety, such as preventing the motors from spooling up or disabling high-gain stabilization while taxiing.

## Tuning & Behavior
*   **-1:** Disabled (Default).
*   **0-103:** Physical GPIO pin number.
*   **Requirement:** Requires [LGR_WOW_POL](LGR_WOW_POL.html) to be set correctly for your specific switch type (Normally Open vs Normally Closed).