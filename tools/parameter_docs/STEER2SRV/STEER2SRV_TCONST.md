---
layout: parameter
name: STEER2SRV_TCONST
display_name: Steering Time Constant
description: The time constant (in seconds) for the steering loop. Controls how quickly the Rover reacts to heading errors.
default_value: 0.75
range: 0.1 2.0
units: s
group: STEER2SRV
visual_asset_id: rover_steering_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/APM_Control/AP_SteerController.cpp#L100
---

# Steering Time Constant (STEER2SRV_TCONST)

## Description
`STEER2SRV_TCONST` defines the "Responsiveness" of the Rover.

*   **Small Value (0.2s):** Very snappy, aggressive steering. Best for high-performance RC cars.
*   **Large Value (1.5s):** Smooth, lazy steering. Best for large, slow tractors or boats.