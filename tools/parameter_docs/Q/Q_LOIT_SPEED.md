---
layout: parameter
name: Q_LOIT_SPEED
display_name: QuadPlane Loiter Horizontal Speed
description: The maximum horizontal speed (in cm/s) for VTOL Loiter mode.
default_value: 1250
range: 0 2000
units: cm/s
group: Q
visual_asset_id: loit_speed_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# QuadPlane Loiter Horizontal Speed (Q_LOIT_SPEED)

## Description
`Q_LOIT_SPEED` determines how fast the QuadPlane can move sideways or forwards while in QLOITER mode.

## Tuning & Behavior
*   **Default Value:** 1250 cm/s (12.5 m/s).
*   **Recommendation:** Set based on your desired cruise speed in hover.