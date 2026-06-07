---
layout: parameter
name: VISO_DELAY_MS
display_name: Visual Odometry Processing Delay
description: The latency (in milliseconds) of the visual odometry data relative to the IMU.
default_value: 10
range: 0 250
units: ms
group: VISO
visual_asset_id: sim_lag_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_VisualOdom/AP_VisualOdom.cpp#L83
---

# Visual Odometry Processing Delay (VISO_DELAY_MS)

## Description
`VISO_DELAY_MS` tells the autopilot how "Old" the vision-based position data is when it arrives.

Vision algorithms (like those in the Intel Realsense T265) take significant time to process images and calculate a pose. If the EKF (Extended Kalman Filter) thinks this data is happening "Now," but it actually represents where the drone was 50ms ago, the position estimate will be unstable. This parameter allows the autopilot to look back in its IMU history and align the vision data with the correct moment in time.

## Tuning & Behavior
*   **Default:** 10 ms.
*   **Recommendation:** Consult your vision system's documentation for its typical latency. For the T265, **50ms to 100ms** is common.
*   **Symptom of incorrect delay:** The drone may "Wobble" or circle slowly while trying to hold position, especially after a quick movement.