---
layout: parameter
name: Q_PILOT_ACCEL_Z
display_name: Pilot Vertical Acceleration
description: The maximum vertical acceleration (in cm/s/s) allowed for pilot-commanded climb or descent.
default_value: 250
range: 50 500
units: cm/s/s
group: Q
visual_asset_id: vtol_control_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# Pilot Vertical Acceleration (Q_PILOT_ACCEL_Z)

## Description
`Q_PILOT_ACCEL_Z` determines how "Snappy" the altitude control feels when you move the throttle stick in VTOL modes (like QHOVER or QLOITER).

It sets the maximum rate at which the vertical velocity can change. A higher value makes the drone react instantly to stick movements, while a lower value makes the climb/descent feel more gradual and "heavy."

## Tuning & Behavior
*   **Default Value:** 250 cm/s/s (0.25g).
*   **High Value (500):** Very aggressive, jumpy altitude control.
*   **Low Value (100):** Very smooth, slow transitions between climbing and descending.
*   **Recommendation:** Keep at **250** for a balanced feel.