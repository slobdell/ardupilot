---
layout: parameter
name: YAW2SRV_DAMP
display_name: Yaw Damping
description: Gain from yaw rate to rudder. Acts as a "Brake" for horizontal rotations to prevent tail-wagging.
default_value: 0
range: 0 2.0
units: 
group: YAW
visual_asset_id: yaw_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/APM_Control/AP_YawController.cpp#L47
---

# Yaw Damping (YAW2SRV_DAMP)

## Description
`YAW2SRV_DAMP` is the "Anti-Wag" gain for planes.

When a plane hits a gust of wind, the tail often "Fishtails" back and forth. This gain uses the gyro to detect that horizontal motion and applies counter-rudder to stop it instantly. This is the most important parameter for a stable, professional-feeling flight on fixed-wing aircraft.

*   **Higher Value:** Stiffer, more damped tail.
*   **Too High:** The rudder will chatter or vibrate.
