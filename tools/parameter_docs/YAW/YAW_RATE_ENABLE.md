---
layout: parameter
name: YAW_RATE_ENABLE
display_name: Yaw Rate Controller Enable
description: Enables or disables the yaw rate PID controller.
default_value: 1
range: 0 1
units: 
group: YAW
visual_asset_id: yaw_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl.cpp#L100
---

# Yaw Rate Controller Enable (YAW_RATE_ENABLE)

## Description
`YAW_RATE_ENABLE` activates the yaw stabilization loop.

*   **1 (Default):** The autopilot actively uses the motors (and rudder/tail) to hold the drone's heading.
*   **0:** Yaw stabilization is disabled. The pilot has 100% manual control over yaw torque. (Highly unstable for multirotors!).