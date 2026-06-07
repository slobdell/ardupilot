---
layout: parameter
name: TECS_LAND_SPDWGT
display_name: TECS Landing Speed Weight
description: Controls the priority of airspeed vs. height error during landing (-1 for default, 0-2 range).
default_value: -1.0
range: -1.0 2.0
units: 
group: TECS
visual_asset_id: tecs_land_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_TECS/AP_TECS.cpp#L100
---

# TECS Landing Speed Weight (TECS_LAND_SPDWGT)

## Description
`TECS_LAND_SPDWGT` is the "Safety vs. Accuracy" slider.

*   **2.0 (Speed Priority):** The plane will aggressively pitch down to regain airspeed if it gets too slow, even if that means diving below the glide slope. Prevents stalls.
*   **0.0 (Height Priority):** The plane will prioritize staying on the glide slope, even if airspeed drops dangerously low.
*   **-1.0 (Default):** Uses the standard `TECS_SPDWEIGHT` value.

## Tuning & Behavior
*   **Default Value:** -1.0.
*   **Recommendation:** Set to **2.0** if you are landing in gusty winds and stall prevention is critical.