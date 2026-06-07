---
layout: parameter
name: Q_LOIT_ACCEL
display_name: QuadPlane Loiter Horizontal Acceleration
description: The maximum horizontal acceleration (in cm/s/s) for VTOL Loiter mode.
default_value: 250
range: 0 980
units: cm/s/s
group: Q
visual_asset_id: loit_accel_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# QuadPlane Loiter Horizontal Acceleration (Q_LOIT_ACCEL)

## Description
`Q_LOIT_ACCEL` controls how quickly the QuadPlane speeds up and slows down in QLOITER mode. 

*   **Higher values** make the drone feel "snappy" and responsive to stick inputs.
*   **Lower values** make the movement feel smooth and cinematic.

## Tuning & Behavior
*   **Default Value:** 250 cm/s/s.
*   **Recommendation:** Set between **200 and 500**.
