---
layout: parameter
name: TECS_OPTIONS
display_name: Extra TECS Options
description: Bitmask to enable specialized energy control behaviors for gliders and speed management.
default_value: 0
range: 0 3
units: 
group: TECS
visual_asset_id: tecs_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_TECS/AP_TECS.cpp#L254
---

# Extra TECS Options (TECS_OPTIONS)

## Description
`TECS_OPTIONS` unlocks advanced cruise behaviors for the Total Energy Control System.

*   **Bit 0 (1): Glider Only.**
    If set, ArduPilot treats the motor as a "Launcher" only. Once at altitude, it optimizes everything for zero-thrust glide performance.
*   **Bit 1 (2): Allow Descent Speedup.**
    Normally, ArduPilot tries to maintain your cruise speed during a descent. If this bit is set, and the drone needs to descend rapidly, it is allowed to increase its airspeed to help bleed off potential energy faster. This makes descents much quicker but carries a risk of overspeeding if the airframe is fragile.

## Tuning & Behavior
*   **Default Value:** 0.
*   **Recommendation:**
    *   **Long-Range Mapping:** Enable **Bit 1** to save time on mission returns (descending from survey altitude).
    *   **Soaring Glider:** Enable **Bit 0**.