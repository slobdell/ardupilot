---
layout: parameter
name: MOT_SPIN_ARM
display_name: Motor Spin armed
description: The idle throttle percentage applied to motors when the vehicle is Armed.
default_value: 0.10
range: 0.0 0.2
units: 
group: MOT
visual_asset_id: mot_spin_arm_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Motors/AP_MotorsMulticopter.cpp#L123
---

# Motor Spin armed (MOT_SPIN_ARM)

## Description
`MOT_SPIN_ARM` sets the idle speed of the motors when you arm the drone (even with the throttle stick at zero).

**Crucial Function:** This idle spin provides "Air Mode" authority. Even at zero throttle, the motors must spin fast enough so that if the autopilot needs to pitch or roll, the motors can respond instantly without stalling or desyncing.

## The Mathematics
The throttle output sent to the ESC is:
$$ \text{Idle Throttle} = \text{MOT\_SPIN\_ARM} $$
(Scaled by `MOT_PWM_MIN` and `MOT_PWM_MAX` if using PWM, or 0-1 range for DShot).

## The Engineer's View
If set too low, motors may stop or stutter during zero-throttle maneuvers (like inverted hangs or rapid descents), causing loss of control ("Desync").
If set too high, the drone will be "floaty" and hard to land, or might even bounce on landing.

## Tuning & Behavior
*   **Default Value:** 0.10 (10%)
*   **Range:** 0.0 - 0.2 (0% - 20%)
*   **Recommendation:**
    *   **5" Racing Quad:** 0.04 - 0.07 (4-7%). Small motors spin up easily.
    *   **Large (15"+) Props:** 0.10 - 0.12 (10-12%). Heavy props need more torque to keep spinning reliably.
    *   **Test:** Arm the drone (props OFF first to verify direction, then ON for idle check). Ensure all motors spin smoothly and don't stutter. Lower the value until they stutter, then add 0.02 or 0.03 safety margin.