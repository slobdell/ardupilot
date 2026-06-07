---
layout: parameter
name: INS_POS
display_name: IMU Position Offset
description: The 3D position (X,Y,Z) of the primary IMU relative to the vehicle's center of gravity.
default_value: 0
range: -5 5
units: m
group: INS
visual_asset_id: antenna_offset_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_InertialSensor/AP_InertialSensor_Params.cpp#L91
---

# IMU Position Offset (INS_POS)

## Description
`INS_POS` (often appearing as `INS_POS_X/Y/Z`) tells the autopilot exactly where the primary flight controller IMU is mounted relative to the drone's balance point (Center of Gravity).

If the flight controller is mounted far away from the center (e.g., at the front of a long airplane), when the plane pitches, the IMU will experience an "Up/Down" acceleration that isn't actually happening to the whole plane. Correctly setting these offsets allows the EKF to mathematically "move" the IMU back to the center of gravity, resulting in a much cleaner and more accurate position estimate.

## Tuning & Behavior
*   **Default:** 0.
*   **Measurement:** Measure the distance from the center of the flight controller to the vehicle's CoG.
    *   **X:** Positive = Forward.
    *   **Y:** Positive = Right.
    *   **Z:** Positive = Down.
*   **Recommendation:** Leave at **0** if the flight controller is within 5-10cm of the center. Accuracy is only critical for high-performance navigation or very large frames.