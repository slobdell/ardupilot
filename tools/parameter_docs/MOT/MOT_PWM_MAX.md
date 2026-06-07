---
layout: parameter
name: MOT_PWM_MAX
display_name: PWM output maximum
description: The maximum PWM output value (in microseconds) sent to the motors.
default_value: 2000
range: 0 2000
units: PWM
group: MOT
visual_asset_id: mot_pwm_max_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Motors/AP_MotorsMulticopter.cpp#L110
---

# PWM output maximum (MOT_PWM_MAX)

## Description
`MOT_PWM_MAX` defines the top of the throttle range sent to your ESCs.

*   **For PWM ESCs:** This must match the calibrated maximum of your ESC. If set too low, you won't get full power. If set too high, you might hit the "Full Throttle" deadzone early.
*   **For DShot:** Ignored for signal generation but used for scaling calculations.

## Tuning & Behavior
*   **Default Value:** 2000 µs.
*   **Recommendation:** Perform an **ESC Calibration**.