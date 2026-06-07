---
layout: parameter
name: WENC_POS_X
display_name: Wheel Encoder Position X
description: X position of the center of the wheel in body frame. Positive X is forward of the origin.
default_value: 0
range: -5 5
units: m
group: WENC
visual_asset_id: wheel_encoder_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_WheelEncoder/AP_WheelEncoder.cpp#L100
---

# Wheel Encoder Position X (WENC_POS_X)

## Description
`WENC_POS_X` defines the forward/backward offset of the wheel relative to the flight controller (or COG).

Accurate positioning helps the EKF account for the "Lever Arm" effect when the vehicle turns.

## Tuning & Behavior
*   **Default Value:** 0 m.