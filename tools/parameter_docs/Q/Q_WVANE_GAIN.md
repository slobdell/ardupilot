---
layout: parameter
name: Q_WVANE_GAIN
display_name: QuadPlane Weathervaning Gain
description: The gain factor for converting wind direction error into yaw rate commands.
default_value: 1
range: 0.1 5
units: 
group: Q
visual_asset_id: vtol_weathervane_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# QuadPlane Weathervaning Gain (Q_WVANE_GAIN)

## Description
`Q_WVANE_GAIN` determines how aggressively the drone turns to face the wind.

## Tuning & Behavior
*   **Default Value:** 1.
*   **High Value:** Snappy response, but might oscillate if the wind is gusty.
*   **Low Value:** Slow, gentle turn into the wind.