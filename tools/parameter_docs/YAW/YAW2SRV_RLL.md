---
layout: parameter
name: YAW2SRV_RLL
display_name: Yaw Coordination Gain
description: Gain that ensures the yaw rate is consistent with the bank angle during a coordinated turn.
default_value: 1.0
range: 0.8 1.2
units: 
group: YAW
visual_asset_id: yaw_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/APM_Control/AP_YawController.cpp#L54
---

# Yaw Coordination Gain (YAW2SRV_RLL)

## Description
`YAW2SRV_RLL` is the "Turn Finisher."

Once a turn is established, this gain fine-tunes the rudder to ensure the plane's tail is perfectly tracking its nose. If the plane tends to skid (tail out) or slip (tail in) during a steady circle, this value is adjusted to fix it.

*   **1.0 (Default):** Physics-based calculation.
*   **Values > 1.0:** Increase yaw into the turn.
*   **Values < 1.0:** Decrease yaw into the turn.
