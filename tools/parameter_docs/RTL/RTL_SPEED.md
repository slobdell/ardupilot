---
layout: parameter
name: RTL_SPEED
display_name: RTL Speed
description: The horizontal speed (in cm/s) the vehicle will fly at during Return to Launch.
default_value: 0
range: 0 2000
units: cm/s
group: RTL
visual_asset_id: rtl_speed_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduCopter/Parameters.cpp#L946
---

# RTL Speed (RTL_SPEED)

## Description
`RTL_SPEED` sets the "Get Home Fast" velocity.

*   **0 (Default):** Use `WPNAV_SPEED` (Waypoint Speed).
*   **> 0:** Use this specific speed for RTL.

## Tuning & Behavior
*   **Default Value:** 0.
*   **Recommendation:** Set slightly higher than your standard waypoint speed if you want the drone to return quickly in an emergency, but ensure it doesn't drain the battery so fast it crashes before arriving.