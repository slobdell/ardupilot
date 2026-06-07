---
layout: parameter
name: TKOFF_PLIM_SEC
display_name: Takeoff Pitch Limit Lead Time
description: The number of seconds before reaching the takeoff target altitude to begin leveling out the pitch.
default_value: 2
range: 0 10
units: s
group: TKOFF
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduPlane/Parameters.cpp#L211
---

# Takeoff Pitch Limit Lead Time (TKOFF_PLIM_SEC)

## Description
`TKOFF_PLIM_SEC` prevents your plane from overshooting its target altitude at the end of a takeoff.

Normally, during takeoff, the autopilot enforces a "Minimum Pitch" to ensure the plane keeps climbing. If this limit is held all the way to the target altitude, the plane's momentum will cause it to fly past the target height before it can level off. This parameter tells the autopilot to start relaxing that pitch limit a few seconds early, allowing for a smooth, graceful transition to level flight exactly at the target altitude.

## Tuning & Behavior
*   **Default:** 2 seconds.
*   **Recommendation:** Leave at **2**. If you find your plane consistently "pops" up 5-10 meters above the takeoff altitude before settling, increase this to **4 or 5**.
*   **0:** Disables the lead time. The pitch limit is held until the altitude is reached.