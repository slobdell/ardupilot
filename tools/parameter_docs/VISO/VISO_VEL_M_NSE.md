---
layout: parameter
name: VISO_VEL_M_NSE
display_name: Visual Odometry Velocity Noise
description: The minimum expected velocity noise (uncertainty) for the vision sensor.
default_value: 0.1
range: 0.05 2.0
units: m/s
group: VISO
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_VisualOdom/AP_VisualOdom.cpp#L107
---

# Visual Odometry Velocity Noise (VISO_VEL_M_NSE)

## Description
`VISO_VEL_M_NSE` tells the EKF how much to trust the velocity (speed) reports from your vision sensor.