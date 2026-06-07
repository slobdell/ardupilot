---
layout: parameter
name: PTCH2SRV_TCONST
display_name: Pitch Time Constant
description: The time constant (in seconds) for the pitch angle loop. Controls how aggressively the plane tries to reach the desired pitch angle.
default_value: 0.5
range: 0.4 1.0
units: s
group: PTCH
visual_asset_id: pid_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/APM_Control/AP_PitchController.cpp#L30
---

# Pitch Time Constant (PTCH2SRV_TCONST)

## Description
`PTCH2SRV_TCONST` defines how fast the plane responds to a pitch command.

If you command a 10-degree pitch up, this parameter determines how quickly the rate controller is asked to get there.

*   **Low Value (0.4):** Snappy response.
*   **High Value (0.8):** Smooth, relaxed response.

## Tuning & Behavior
*   **Default Value:** 0.5 seconds.
*   **Recommendation:** Match this to the physical capabilities of your plane. A heavy cargo plane physically cannot pitch up as fast as a fighter jet, so it needs a larger time constant.
