---
layout: parameter
name: Q_ESC_CAL
display_name: QuadPlane ESC Calibration
description: Enables ESC calibration for the VTOL motors only.
default_value: 0
range: 0 1
units: 
group: Q
visual_asset_id: vtol_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# QuadPlane ESC Calibration (Q_ESC_CAL)

## Description
`Q_ESC_CAL` allows you to calibrate the vertical lift motors without affecting the forward pusher motor.

## Tuning & Behavior
*   **0 (Disabled):** Normal operation.
*   **1 (Enabled):** On next boot, the VTOL motors will pass-through the throttle stick for calibration (High/Low endpoint setting). The forward motor will remain safe.