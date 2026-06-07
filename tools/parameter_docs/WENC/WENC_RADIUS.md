---
layout: parameter
name: WENC_RADIUS
display_name: Wheel Radius
description: The radius of the wheel (in meters) to convert rotations to distance.
default_value: 0.05
range: 0.001 10.0
units: m
group: WENC
visual_asset_id: wheel_encoder_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_WheelEncoder/AP_WheelEncoder.cpp#L45
---

# Wheel Radius (WENC_RADIUS)

## Description
`WENC_RADIUS` defines the physical size of the wheel being monitored. 

This value is used by the autopilot to translate "Wheel Rotations" (from the encoder) into "Meters Traveled" (for the EKF). If this value is incorrect, the drone will have a massive error in its position and speed estimate when relying on odometry.

## The Mathematics
$$ \text{Distance} = \text{Rotations} \times 2\pi \times \text{WENC_RADIUS} $$

## Tuning & Behavior
*   **Default:** 0.05 m (5 cm).
*   **Recommendation:** Measure the wheel carefully with calipers. Include the tire if applicable.
*   **Note:** If your Rover is moving 10m in reality but the GCS says 11m, your radius parameter is likely 10% too large.