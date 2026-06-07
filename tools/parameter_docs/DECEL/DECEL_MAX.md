---
layout: parameter
name: DECEL_MAX
display_name: Throttle deceleration max
description: Maximum deceleration in m/s/s that the throttle controller will command.
default_value: 0
range: 0 10
units: m/s/s
group: DECEL
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/APM_Control/AR_AttitudeControl.cpp
---

# Throttle deceleration max (DECEL_MAX)

## Description
Limits the maximum rate at which the Rover's speed can be reduced by the automatic throttle controller.
*   **A value of 0 means no limit (or uses ATC_ACCEL_MAX).**