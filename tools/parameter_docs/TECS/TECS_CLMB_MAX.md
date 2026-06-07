---
layout: parameter
name: TECS_CLMB_MAX
display_name: Maximum Climb Rate
description: The maximum vertical speed (in m/s) the autopilot will demand during a climb.
default_value: 5.0
range: 1 15
units: m/s
group: TECS
visual_asset_id: tecs_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_TECS/AP_TECS.cpp#L101
---

# Maximum Climb Rate (TECS_CLMB_MAX)

## Description
`TECS_CLMB_MAX` sets the "Speedometer Limit" for going up.

Even if you command a 100-meter climb, the drone will limit its vertical ascent speed to this value. This ensures the climb is steady and doesn't exceed the motor's power limits or cause a high-pitch stall.

## Tuning & Behavior
*   **Default Value:** 5.0 m/s.
*   **Recommendation:** Set this to roughly **75%** of your plane's physical maximum climb rate at full throttle.
