---
layout: parameter
name: YAW2SRV_SLIP
display_name: Sideslip Control Gain
description: Gain from lateral acceleration to demanded yaw rate. Used to coordinate turns by detecting and correcting sideslip.
default_value: 0
range: 0 4.0
units: 
group: YAW
visual_asset_id: yaw_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/APM_Control/AP_YawController.cpp#L33
---

# Sideslip Control Gain (YAW2SRV_SLIP)

## Description
`YAW2SRV_SLIP` helps a plane fly "Straight" through the air during turns.

For aircraft with a significant vertical tail or fuselage area, a sideslip causes lateral (sideways) acceleration. This parameter uses the accelerometer to detect that sideways force and automatically applies rudder to cancel it out, ensuring the plane's nose is always pointing exactly where it is going.

*   **Higher Value:** More aggressive rudder correction to keep the ball centered.
*   **0:** Disabled.

## Tuning & Behavior
*   **Default Value:** 0.
*   **Recommendation:** Only tune this after [YAW2SRV_DAMP](YAW2SRV_DAMP.html) is set. Do not use on flying wings or gliders without a large vertical tail.
