---
layout: parameter
name: Q_WVANE_VELZ_MAX
display_name: QuadPlane Weathervane Max Vertical Speed
description: The maximum vertical speed (in m/s) at which weathervaning is active.
default_value: 0
range: 0 5
units: m/s
group: Q
visual_asset_id: vtol_weathervane_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# QuadPlane Weathervane Max Vertical Speed (Q_WVANE_VELZ_MAX)

## Description
`Q_WVANE_VELZ_MAX` prevents yawing during fast climbs or descents.

If you are rocketing up to altitude, you usually want to keep the heading locked. This parameter disables the wind-turning logic if the vertical speed exceeds the threshold.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled).