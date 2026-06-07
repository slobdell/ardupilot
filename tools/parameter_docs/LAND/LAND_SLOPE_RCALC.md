---
layout: parameter
name: LAND_SLOPE_RCALC
display_name: Land Slope Recalculate Altitude
description: The altitude (in meters) at which the landing slope is recalculated.
default_value: 2.0
range: 0 5
units: m
group: LAND
visual_asset_id: land_flare_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/Parameters.cpp#L100
---

# Land Slope Recalculate Altitude (LAND_SLOPE_RCALC)

## Description
`LAND_SLOPE_RCALC` is a correction threshold.

If the plane is too high or too low on the approach, the autopilot will try to fly back to the ideal line. However, once the plane gets very close to the ground (below this altitude), it stops trying to correct the slope and commits to the current path to avoid erratic pitch changes just before touchdown.

## Tuning & Behavior
*   **Default Value:** 2.0 m.
*   **Recommendation:** Keep low. Recalculating the slope at 20m is fine; recalculating at 0.5m might cause a crash.