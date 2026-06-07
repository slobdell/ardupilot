---
layout: parameter
name: VEL_M_NSE
display_name: Visual odometry velocity measurement noise
description: Visual odometry velocity measurement noise in m/s.
default_value: 0.1
range: 0.05 5.0
units: m/s
group: VEL
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_VisualOdom/AP_VisualOdom.cpp#L91
---

# VEL_M_NSE: Visual odometry velocity measurement noise

## Description
Visual odometry velocity measurement noise in m/s.

## Values
- **Range:** 0.05 to 5.0
- **Units:** m/s
- **Default:** 0.1

## Description
This parameter sets the "Trust" level for the velocity reported by a Visual Odometry (VO) system (like Intel RealSense T265 or OpenMV).

- **Function:** It tells the EKF how noisy the velocity data is.
- **Lower Value:** The EKF trusts the visual odometry velocity more than other sensors (like GPS or IMU integration). Use this if your VO system is very accurate and stable.
- **Higher Value:** The EKF trusts the visual odometry less. Use this if the VO system drifts or jumps frequently.

