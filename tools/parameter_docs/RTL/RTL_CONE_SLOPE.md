---
layout: parameter
name: RTL_CONE_SLOPE
display_name: RTL Cone Slope
description: Defines the slope of the "Virtual Cone" above the home point.
default_value: 3.0
range: 0.5 10.0
units: 
group: RTL
visual_asset_id: rtl_alt_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduCopter/Parameters.cpp#L946
---

# RTL Cone Slope (RTL_CONE_SLOPE)

## Description
`RTL_CONE_SLOPE` creates a virtual funnel above the landing spot.

If the drone is very close to home but very high up, it doesn't need to climb to `RTL_ALT`. It can just descend. This parameter defines how steep that descent can be.

*   **Low Value:** Shallow cone. Drone flies further out before descending.
*   **High Value:** Steep cone. Drone can descend steeply.

## Tuning & Behavior
*   **Default Value:** 3.0 (3:1 slope).
*   **0:** Disabled (Always climb to `RTL_ALT` first).
