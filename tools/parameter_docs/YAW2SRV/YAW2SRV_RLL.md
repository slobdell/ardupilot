---
layout: parameter
name: YAW2SRV_RLL
display_name: Yaw Coordination Gain (Bank Angle)
description: Adjusts the yaw rate target based on the bank angle to maintain coordinated turns.
default_value: 1.0
range: 0.8 1.2
units: 
group: YAW2SRV
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/APM_Control/AP_YawController.cpp#L60
---

# Yaw Coordination Gain (Bank Angle) (YAW2SRV_RLL)

## Description
`YAW2SRV_RLL` fine-tunes the turn geometry.

For a fixed-wing aircraft to turn efficiently, the nose must rotate (yaw) at a specific rate that matches the bank angle and airspeed. If the yaw is too slow, the plane slips into the turn. If too fast, it skids out. This parameter adjusts the calculation of that "perfect" yaw rate.

## Tuning & Behavior
*   **Default:** 1.0 (Ideal physics).
*   **Values > 1.0:** Demands *more* yaw into the turn.
*   **Values < 1.0:** Demands *less* yaw into the turn.
*   **Significance:** If you have accurate airspeed calibration, leave this at **1.0**. If you see persistent sideslip during steady turns, adjust [YAW2SRV_SLIP](YAW2SRV_SLIP.html) first.