---
layout: parameter
name: EK3_ERR_THRESH
display_name: EKF3 Lane Relative Error Sensitivity Threshold
description: Threshold for switching between EKF lanes. Lowering this makes lane switching more sensitive to smaller error differences.
default_value: 0.2
range: 0.05 1
units: 
group: EK3
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_NavEKF3/AP_NavEKF3.cpp
---

# EKF3 Lane Relative Error Sensitivity Threshold (EK3_ERR_THRESH)

## Description
Tuning for the multi-lane EKF logic. If a standby EKF lane is performing better than the primary by more than this threshold, the flight controller may switch to the healthier lane.
