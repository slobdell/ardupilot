---
layout: parameter
name: PLND_CAM_POS_X
display_name: Camera X Position Offset
description: The forward/backward distance (in meters) of the landing camera relative to the drone's center of gravity.
default_value: 0
range: -5 5
units: m
group: PLND
visual_asset_id: cam_offset_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PrecLand/AC_PrecLand.cpp#L81
---

# Camera X Position Offset (PLND_CAM_POS_X)

## Description
`PLND_CAM_POS_X` tells the autopilot exactly where the camera is mounted on the drone.

For precision landing to work perfectly, the flight controller needs to know the "Lever Arm" effect. If the camera is 10cm forward of the center of gravity, and the drone tilts forward, the camera moves. Without this offset, the drone might "hunt" or circle the target because it thinks it has moved more (or less) than it actually has.

## The Engineer's View
This parameter defines the longitudinal offset in the body frame.
*   **Positive X:** Camera is in front of the center.
*   **Negative X:** Camera is behind the center.

The values are used to transform the camera's raw sight-line vector into a global position relative to the vehicle's navigation origin.

## Tuning & Behavior
*   **Default Value:** 0 m.
*   **Recommendation:** Measure the distance from the lens center to the center of your flight controller's IMU. Enter the value in meters (e.g. 0.1 for 10cm).
