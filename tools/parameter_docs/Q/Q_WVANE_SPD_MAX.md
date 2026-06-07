---
layout: parameter
name: Q_WVANE_SPD_MAX
display_name: QuadPlane Weathervane Max Speed
description: The maximum groundspeed (in m/s) at which weathervaning is active.
default_value: 0
range: 0 10
units: m/s
group: Q
visual_asset_id: vtol_weathervane_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# QuadPlane Weathervane Max Speed (Q_WVANE_SPD_MAX)

## Description
`Q_WVANE_SPD_MAX` disables weathervaning if the drone is moving fast.

If you are repositioning the drone (e.g. loitering at 5 m/s), you want it to point in the direction of travel, not the direction of the wind. This parameter ensures the navigation controller has priority over the wind controller when moving.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled/Always Active).
*   **Recommendation:** Set to **1 or 2 m/s**.