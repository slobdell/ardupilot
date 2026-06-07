---
layout: parameter
name: YAW_RATE_FF
display_name: Yaw Rate Feed-Forward
description: The feed-forward gain for the yaw axis. Provides immediate motor response to pilot input.
default_value: 0
range: 0 0.5
units: 
group: YAW
visual_asset_id: yaw_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl.cpp#L100
---

# Yaw Rate Feed-Forward (YAW_RATE_FF)

## Description
`YAW_RATE_FF` gives the drone a "Head Start" on turning.

It injects a portion of your stick command directly into the motors, bypassing the PID calculation. This makes the drone feel more connected and less "mushy."

## Tuning & Behavior
*   **Default Value:** 0.
*   **Recommendation:** Tune until the drone starts rotating exactly when you move the stick, without waiting for the error to build up.
