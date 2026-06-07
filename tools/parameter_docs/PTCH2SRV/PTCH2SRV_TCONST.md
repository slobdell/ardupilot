---
layout: parameter
name: PTCH2SRV_TCONST
display_name: Pitch Controller Time Constant
description: The time (in seconds) for the pitch controller to achieve 63% of a requested angle change.
default_value: 0.5
range: 0.4 1.0
units: s
group: PTCH
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/APM_Control/AP_PitchController.cpp#L36
---

# Pitch Controller Time Constant (PTCH2SRV_TCONST)

## Description
`PTCH2SRV_TCONST` defines the "Crispness" of the pitch response for fixed-wing aircraft.

It represents the time constant of the commanded pitch. A lower value makes the plane pitch up or down more aggressively to reach its target, while a higher value makes the movement smoother and more gradual.

## Tuning & Behavior
*   **Default:** 0.5 seconds.
*   **Recommendation:** Most models fly well with **0.5**. For high-performance racing planes, you can reduce this toward **0.4**. For large, heavy drones, you may need to increase it toward **0.7** or **1.0**.
*   **Note:** If set too low, the plane may oscillate or "hunt" for the target pitch angle.