---
layout: parameter
name: LGR_WOW_POL
display_name: Weight-On-Wheels Polarity
description: Sets whether the Weight-On-Wheels (WOW) sensor signal is Active-High or Active-Low.
default_value: 0
range: 0 1
units: 
group: LGR
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_LandingGear/AP_LandingGear.cpp#L67
---

# Weight-On-Wheels Polarity (LGR_WOW_POL)

## Description
`LGR_WOW_POL` calibrates the autopilot for your specific Weight-On-Wheels (WOW) sensor hardware.

A WOW sensor (like a microswitch on the landing strut) tells the autopilot if the aircraft is physically supported by the ground.

*   **0: Low.** Signal is 0V when there is weight on the wheels.
*   **1: High.** Signal is 3.3V/5V when there is weight on the wheels.