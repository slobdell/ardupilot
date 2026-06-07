---
layout: parameter
name: H_YAW_TRIM
display_name: Tail Rotor Trim
description: Fixed offset applied to yaw output to minimize yaw I-term contribution needed to counter rotor drag.
default_value: 0.0
range: 0 1
units: 
group: H
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Motors/AP_MotorsHeli_Single.cpp
---

# Tail Rotor Trim (H_YAW_TRIM)

## Description
Provides a static offset to the tail rotor output (primarily for DDFP tails) to account for constant main-rotor torque during hover.
