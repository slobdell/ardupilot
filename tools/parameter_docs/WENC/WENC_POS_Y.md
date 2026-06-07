---
layout: parameter
name: WENC_POS_Y
display_name: Wheel Encoder Position Y
description: Y position of the center of the wheel in body frame. Positive Y is to the right of the origin.
default_value: 0
range: -5 5
units: m
group: WENC
visual_asset_id: wheel_encoder_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_WheelEncoder/AP_WheelEncoder.cpp#L100
---

# Wheel Encoder Position Y (WENC_POS_Y)

## Description
`WENC_POS_Y` defines the left/right offset of the wheel.

## Tuning & Behavior
*   **Default Value:** 0 m.