---
layout: parameter
name: WENC_CPR
display_name: Wheel Encoder Counts Per Revolution
description: The number of encoder counts (ticks) generated for one full revolution of the wheel.
default_value: 0
range: 0 100000
units: 
group: WENC
visual_asset_id: wheel_encoder_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_WheelEncoder/AP_WheelEncoder.cpp#L37
---

# Wheel Encoder Counts Per Revolution (WENC_CPR)

## Description
`WENC_CPR` calibrates the encoder resolution.

If your encoder has 1000 lines and uses quadrature (4x) decoding, the CPR is 4000. Correct setting is essential for accurate odometry.

## Tuning & Behavior
*   **Default Value:** 0 (or Driver Default).
*   **Calculation:** `Lines * 4` for Quadrature.