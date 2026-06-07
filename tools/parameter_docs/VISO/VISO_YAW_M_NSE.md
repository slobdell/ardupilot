---
layout: parameter
name: VISO_YAW_M_NSE
display_name: Visual Odometry Yaw Noise
description: The expected noise (in radians) for yaw measurements from the visual odometry sensor.
default_value: 0.2
range: 0.05 1.0
units: rad
group: VISO
visual_asset_id: sim_sensor_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_VisualOdom/AP_VisualOdom.cpp#L100
---

# Visual Odometry Yaw Noise (VISO_YAW_M_NSE)

## Description
`VISO_YAW_M_NSE` defines how much the autopilot trusts the heading data coming from a Visual Odometry (VO) sensor (like an Intel T265).

*   **Low Value:** High trust. The EKF will rely heavily on the camera for heading.
*   **High Value:** Low trust. The EKF will rely more on the IMU and Compass.

## Tuning & Behavior
*   **Default Value:** 0.2 rad.
*   **Recommendation:** If the drone's heading "Glitchy" while using VO, increase this value to reduce the camera's influence.