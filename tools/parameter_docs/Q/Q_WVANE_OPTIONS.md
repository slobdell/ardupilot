---
layout: parameter
name: Q_WVANE_OPTIONS
display_name: QuadPlane Weathervane Options
description: Bitmask of advanced weathervaning options.
default_value: 0
range: 0 1
units: 
group: Q
visual_asset_id: vtol_weathervane_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# QuadPlane Weathervane Options (Q_WVANE_OPTIONS)

## Description
`Q_WVANE_OPTIONS` enables specialized behaviors.

*   **Bit 0:** Pitch into wind. Instead of yawing, the drone will pitch its nose down into the wind. This is useful for tailsitters or tilt-rotors that generate lift from their wings even in hover.

## Tuning & Behavior
*   **Default Value:** 0.