---
layout: parameter
name: TECS_PTCH_FF_K
display_name: Pitch Feed-Forward Gain
description: Predictive pitch adjustment based on airspeed demand.
default_value: 0.0
range: -5.0 0.0
units: rad/(m/s)
group: TECS
visual_asset_id: tecs_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_TECS/AP_TECS.cpp#L265
---

# Pitch Feed-Forward Gain (TECS_PTCH_FF_K)

## Description
`TECS_PTCH_FF_K` allows the autopilot to "Anticipate" how much pitch is needed to achieve a target airspeed, rather than waiting for an airspeed error to build up.

When you demand a higher airspeed, the plane naturally needs to point its nose down. This feed-forward gain applies that pitch command immediately.

*   **0.0 (Default):** Feature is disabled.
*   **Negative Values:** Apply downward pitch for increased speed demand.

## Tuning & Behavior
*   **Default:** 0.
*   **Recommendation (Gliders):** Start with **-0.04**.
*   **Recommendation (Draggy planes):** Start with **-0.08**.
*   **Effect:** Reduces the "Lag" in airspeed tracking during altitude changes. If the nose drops too aggressively when you speed up, reduce the magnitude (make it less negative).