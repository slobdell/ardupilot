---
layout: parameter
name: RLL2SRV_TCONST
display_name: Steering Time Constant
description: The time (in seconds) for the steering controller to achieve 63% of a requested angle change.
default_value: 0.75
range: 0.4 1.0
units: s
group: RLL2SRV
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/APM_Control/AP_SteerController.cpp#L35
---

# Steering Time Constant (RLL2SRV_TCONST)

## Description
`RLL2SRV_TCONST` defines the "Responsiveness" of the steering system for Rovers and the ground-handling of Planes.

A lower value makes the steering more aggressive and "snappy," forcing the vehicle to reach its target angle as quickly as possible. A higher value makes the steering feel "lazy" or more gradual.

## Tuning & Behavior
*   **Default:** 0.75 seconds.
*   **Recommendation (Rover):** Leave at **0.75**.
*   **Recommendation (Plane):** Use **0.5** for better ground handling during high-speed takeoff runs.
*   **Note:** If set too low, the steering may oscillate (weaving) even at low speeds.