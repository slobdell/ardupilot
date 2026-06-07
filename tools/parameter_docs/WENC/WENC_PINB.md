---
layout: parameter
name: WENC_PINB
display_name: Wheel Encoder Pin B (Instance 1)
description: The physical pin number for the second phase (B) of the quadrature encoder.
default_value: -1
range: -1 103
units: 
group: WENC
visual_asset_id: wheel_encoder_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_WheelEncoder/AP_WheelEncoder.cpp#L84
---

# Wheel Encoder Pin B (WENC_PINB)

## Description
`WENC_PINB` defines the input pin for Phase B of the primary wheel encoder. 

In a quadrature encoder, Phase B is offset from Phase A. By comparing the timing of the pulses on these two pins, the autopilot can detect if the wheel is spinning forward or backward.

## Tuning & Behavior
*   **Default:** -1.
*   **Direction Fix:** If your Rover reports it is moving forward when it is actually reversing, swap the values of `WENC_PINA` and `WENC_PINB` in the parameters.