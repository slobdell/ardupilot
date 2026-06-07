---
layout: parameter
name: YAW2SRV_SLIP
display_name: Sideslip Coordination Gain
description: Active coordination for turns using lateral acceleration feedback to the rudder.
default_value: 0
range: 0 4.0
units: 
group: YAW2SRV
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/APM_Control/AP_YawController.cpp#L36
---

# Sideslip Coordination Gain (YAW2SRV_SLIP)

## Description
`YAW2SRV_SLIP` is used to achieve perfectly "Coordinated" turns (where the ball stays centered in a physical cockpit).

When an aircraft banks into a turn, it often experiences "Sideslip" – moving through the air slightly sideways. This parameter uses the accelerometer to sense that sideways force and automatically applies the correct amount of rudder to keep the nose pointed exactly where the plane is flying.

*   **0: Disabled.** Standard for flying wings and gliders.
*   **Non-Zero:** Active coordination for planes with a vertical tail.

## Tuning & Behavior
*   **Default:** 0.
*   **Usage:** Only use this for traditional aircraft with a large vertical fin/rudder and significant fuselage side area. 
*   **Tuning Order:** Tune this **Last**, after [YAW2SRV_DAMP](YAW2SRV_DAMP.html) and [YAW2SRV_INT](YAW2SRV_INT.html) are finalized.