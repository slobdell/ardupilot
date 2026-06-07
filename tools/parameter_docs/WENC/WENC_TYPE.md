---
layout: parameter
name: WENC_TYPE
display_name: Wheel Encoder Type (Instance 1)
description: Selects the hardware type for the first wheel encoder.
default_value: 0
range: 0 10
units: 
group: WENC
visual_asset_id: wenc_type_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_WheelEncoder/AP_WheelEncoder.cpp#L30
---

# Wheel Encoder Type (WENC_TYPE)

## Description
`WENC_TYPE` enables the primary wheel encoder. 

Wheel encoders provide high-precision distance and velocity measurements by counting the rotations of the vehicle's wheels. This is critical for Rovers operating in GPS-denied environments (Dead Reckoning) or for precise low-speed positioning.

*   **0: None.** Disabled.
*   **1: Quadrature.** For standard optical or magnetic encoders with A/B signal phases.
*   **10: SITL Quadrature.** For simulation testing.

## Tuning & Behavior
*   **Reboot Required:** Yes.
*   **Integration:** Once enabled, you must also configure the counts per revolution ([WENC_CPR](WENC_CPR.html)) and the wheel radius ([WENC_RADIUS](WENC_RADIUS.html)).