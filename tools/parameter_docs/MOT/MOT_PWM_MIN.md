---
layout: parameter
name: MOT_PWM_MIN
display_name: PWM output minimum
description: The minimum PWM output value (in microseconds) sent to the motors.
default_value: 1000
range: 0 2000
units: PWM
group: MOT
visual_asset_id: mot_pwm_min_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Motors/AP_MotorsMulticopter.cpp#L101
---

# PWM output minimum (MOT_PWM_MIN)

## Description
`MOT_PWM_MIN` defines the bottom of the throttle range sent to your ESCs.

*   **For PWM ESCs:** This must match the calibrated minimum of your ESC. If set too low, the motors might not start. If set too high, the motors might spin immediately upon arming (even if `MOT_SPIN_ARM` is 0).
*   **For DShot:** This parameter is generally ignored for the signal itself (digital uses 0-2000 range internally), but ArduPilot still uses it for some internal scaling calculations.

## Tuning & Behavior
*   **Default Value:** 1000 µs.
*   **Recommendation:** Perform an **ESC Calibration**. This will automatically detect the correct range.
*   **Safety:** Ensure this is lower than `MOT_SPIN_ARM` + overhead to prevent accidental spins.