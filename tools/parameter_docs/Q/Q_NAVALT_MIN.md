---
layout: parameter
name: Q_NAVALT_MIN
display_name: QuadPlane Minimum Navigation Altitude
description: The altitude (in meters) below which the QuadPlane will not attempt to navigate horizontally.
default_value: 0
range: 0 50
units: m
group: Q
visual_asset_id: vtol_land_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# QuadPlane Minimum Navigation Altitude (Q_NAVALT_MIN)

## Description
`Q_NAVALT_MIN` prevents the drone from leaning over to fly to a waypoint while it is still on the ground or taking off.

The drone must climb vertically to this height *before* it starts moving horizontally toward the first waypoint.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled).
*   **Recommendation:** Set to **3 or 5 meters** to ensure the drone clears obstacles/grass before tilting.