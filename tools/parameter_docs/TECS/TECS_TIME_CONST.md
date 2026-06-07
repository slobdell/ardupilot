---
layout: parameter
name: TECS_TIME_CONST
display_name: TECS Time Constant
description: The time constant (in seconds) for the altitude and speed control loops. Controls the overall aggressiveness of the TECS controller.
default_value: 5.0
range: 3.0 10.0
units: s
group: TECS
visual_asset_id: tecs_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_TECS/AP_TECS.cpp#L103
---

# TECS Time Constant (TECS_TIME_CONST)

## Description
`TECS_TIME_CONST` defines how fast the plane tries to fix altitude and speed errors.

It is effectively the "Damping" of the whole navigation system.

*   **Small Value (3.0s):** Fast, aggressive control. The plane will snap back to the target altitude and speed quickly. Can cause the motor to pulse and the nose to bob.
*   **Large Value (10.0s):** Smooth, relaxed control. The plane takes its time to reach the target. Good for long-range efficient cruising.

## Tuning & Behavior
*   **Default Value:** 5.0 seconds.
*   **Recommendation:** Leave at **5.0** for most planes. Increase to **7.0** for very large, slow UAVs to prevent the autopilot from over-correcting.
