---
layout: parameter
name: Q_FWD_THR_GAIN
display_name: QuadPlane Forward Throttle Gain
description: The gain for converting pitch angle demand into forward throttle output.
default_value: 0.5
range: 0 5
units: 
group: Q
visual_asset_id: vtol_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# QuadPlane Forward Throttle Gain (Q_FWD_THR_GAIN)

## Description
`Q_FWD_THR_GAIN` determines how aggressively the forward motor spins up when the drone tilts forward in QLOITER.

If `Q_FWD_THR_USE` is enabled, this parameter translates the "tilt demand" (e.g., 5 degrees nose down) into a throttle percentage for the pusher prop.

## Tuning & Behavior
*   **Default Value:** 0.5
*   **Recommendation:** Increase until the drone holds position in wind without needing to pitch down excessively.