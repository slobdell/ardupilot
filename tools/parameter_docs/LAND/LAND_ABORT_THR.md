---
layout: parameter
name: LAND_ABORT_THR
display_name: Land Abort Throttle
description: The throttle percentage that triggers an automatic landing abort if exceeded.
default_value: 0
range: 0 100
units: '%'
group: LAND
visual_asset_id: land_abort_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduCopter/Parameters.cpp#L100
---

# Land Abort Throttle (LAND_ABORT_THR)

## Description
`LAND_ABORT_THR` triggers a Go-Around if the motor demand is too high.

If the drone is descending but needs 90% throttle to maintain the path (due to wind shear or a heavy payload), it's dangerous to continue. This parameter forces an abort.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled).
*   **Recommendation:** Set to **90%** to ensure you always have headroom to climb out.