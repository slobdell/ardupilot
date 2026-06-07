---
layout: parameter
name: WENC_POS
display_name: Wheel Encoder Position Offset
description: The 3D position (X,Y,Z) of the wheel encoder relative to the vehicle center of gravity.
default_value: 0
range: -5 5
units: m
group: WENC
visual_asset_id: antenna_offset_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_WheelEncoder/AP_WheelEncoder.cpp#L100
---

# Wheel Encoder Position Offset (WENC_POS)

## Description
`WENC_POS` (often appearing as `WENC_POS_X/Y/Z`) tells the autopilot exactly where the wheel is located on your frame.

If you are using encoders for high-precision autonomous navigation (like indoor mapping), the autopilot must know if the wheel is at the front, back, or side of the drone. This allows the EKF to correctly translate the wheel's rotation into the movement of the vehicle's center of gravity.

*   **X:** Positive = Forward.
*   **Y:** Positive = Right.
*   **Z:** Positive = Down.