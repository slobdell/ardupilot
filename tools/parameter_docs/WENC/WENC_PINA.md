---
layout: parameter
name: WENC_PINA
display_name: Wheel Encoder Pin A (Instance 1)
description: The physical pin number for the first phase (A) of the quadrature encoder.
default_value: -1
range: -1 103
units: 
group: WENC
visual_asset_id: wheel_encoder_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_WheelEncoder/AP_WheelEncoder.cpp#L77
---

# Wheel Encoder Pin A (WENC_PINA)

## Description
`WENC_PINA` defines the input pin for Phase A of the primary wheel encoder. 

Wheel encoders typically use two pins (A and B) to determine both speed and direction of rotation. Phase A provides the primary pulse count.

## Tuning & Behavior
*   **Default:** -1.
*   **Setup:** Set this to the digital input pin connected to your encoder's A channel. If using an IOMCU-equipped board (like Pixhawk), these must typically be AUX pins configured as GPIO.
*   **Integration:** You must also configure [WENC_PINB](WENC_PINB.html) for quadrature decoding to function.