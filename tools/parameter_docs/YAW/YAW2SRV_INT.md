---
layout: parameter
name: YAW2SRV_INT
display_name: Sideslip Control Integrator
description: Integral gain for sideslip control. Trims the rudder over time to eliminate persistent lateral acceleration.
default_value: 0
range: 0 2.0
units: 
group: YAW
visual_asset_id: yaw_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/APM_Control/AP_YawController.cpp#L40
---

# Sideslip Control Integrator (YAW2SRV_INT)

## Description
`YAW2SRV_INT` acts like a "Self-Trimming Rudder."

If your plane naturally pulls to one side because of motor torque or a warped tail, the I-term learns the required offset to keep the flight perfectly coordinated without any pilot input.
