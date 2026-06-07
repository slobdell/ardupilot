---
layout: parameter
name: TECS_HDEM_TCONST
display_name: Height Demand Time Constant
description: The time constant (in seconds) for smoothing requested altitude changes.
default_value: 3.0
range: 1.0 5.0
units: s
group: TECS
visual_asset_id: tecs_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_TECS/AP_TECS.cpp#L284
---

# Height Demand Time Constant (TECS_HDEM_TCONST)

## Description
`TECS_HDEM_TCONST` defines how "Softly" the autopilot reacts when a new altitude is requested.

When a mission or a pilot (in FBWB mode) changes the target altitude, the autopilot doesn't try to reach it instantly. Instead, it passes the request through a low-pass filter to create a smooth climb or descent path. This parameter sets the "Slowness" of that filter.

*   **Higher Value (e.g. 5.0):** Very smooth, gradual altitude changes.
*   **Lower Value (e.g. 1.0):** More aggressive reaction to altitude commands.

## Tuning & Behavior
*   **Default:** 3.0 seconds.
*   **Recommendation:** Leave at **3.0** for standard transport or mapping drones. Reduce to **1.5 or 2.0** for high-performance aircraft that need to react quickly to terrain changes.
*   **Effect:** Increasing this value reduces "Pitch pumping" (oscillations in pitch) during altitude transitions.