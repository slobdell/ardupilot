---
layout: parameter
name: RLL2SRV_TCONST
display_name: Roll Time Constant
description: The time constant (in seconds) for the roll angle loop. Controls how aggressively the plane tries to reach the desired bank angle.
default_value: 0.5
range: 0.4 1.0
units: s
group: RLL
visual_asset_id: roll_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/APM_Control/AP_RollController.cpp#L30
---

# Roll Time Constant (RLL2SRV_TCONST)

## Description
`RLL2SRV_TCONST` defines the "Lag" between demanding a bank angle and achieving it.

It converts the Angle Error into a Desired Rate.
$$ \text{Rate}_{cmd} = \frac{\text{Angle}_{error}}{\text{TCONST}} $$

*   **Small Value (0.4):** High Gain. The plane tries to snap to the angle instantly. Can cause oscillation.
*   **Large Value (0.8):** Low Gain. The plane rolls lazily to the angle.

## Tuning & Behavior
*   **Default Value:** 0.5 seconds.
*   **Recommendation:**
    *   **Aerobatic Plane:** 0.3 - 0.4.
    *   **Large UAV / Glider:** 0.6 - 0.8.
