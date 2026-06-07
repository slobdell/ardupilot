---
layout: parameter
name: VISO_POS
display_name: Visual Odometry Position Offset
description: 3D position of the VIO camera relative to the vehicle center of gravity.
default_value: 0
range: -5 5
units: m
group: VISO
visual_asset_id: antenna_offset_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_VisualOdom/AP_VisualOdom.cpp#L62
---

# Visual Odometry Position Offset (VISO_POS)

## Description
`VISO_POS` (often appearing as `VISO_POS_X`, `VISO_POS_Y`, `VISO_POS_Z`) defines the physical location of the camera lens relative to the drone's center of gravity (CoG).

Correctly setting these offsets allows the autopilot to perform "Lever Arm Compensation." This ensures that when the drone rotates (pitches or rolls), the resulting camera movement isn't mistaken for actual horizontal translation.

*   **X:** Positive = Forward of CoG.
*   **Y:** Positive = Right of CoG.
*   **Z:** Positive = Below CoG.

## Tuning & Behavior
*   **Default:** 0.
*   **Measurement:** Use a tape measure to find the distance from the center of the flight controller (or the vehicle's balance point) to the center of the camera lenses.
*   **Accuracy:** Small errors (1-2cm) are usually acceptable, but errors > 5cm can cause instability in position hold during aggressive maneuvers.