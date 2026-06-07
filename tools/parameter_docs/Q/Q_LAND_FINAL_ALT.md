---
layout: parameter
name: Q_LAND_FINAL_ALT
display_name: QuadPlane Land Final Altitude
description: The altitude (in meters) where the QuadPlane switches to its final descent speed.
default_value: 6
range: 0 50
units: m
group: Q
visual_asset_id: vtol_land_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# Q_LAND_FINAL_ALT: QuadPlane Land Final Altitude

## Description
The altitude (in meters) where the QuadPlane switches to its final descent speed.

## Description
`Q_LAND_FINAL_ALT` is the VTOL equivalent of `LAND_ALT_LOW`.

When the QuadPlane descends to this height, it slows down to `Q_LAND_FINAL_SPD` to ensure a soft touchdown.

## Tuning & Behavior
*   **Default Value:** 6 meters.
*   **Recommendation:** Increase to **10-15m** for heavy aircraft to give the vertical velocity controller more time to stabilize before contact.