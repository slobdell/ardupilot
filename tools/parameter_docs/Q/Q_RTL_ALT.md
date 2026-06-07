---
layout: parameter
name: Q_RTL_ALT
display_name: QuadPlane RTL Altitude
description: The altitude (in meters) relative to home for QuadPlane RTL.
default_value: 15
range: 0 100
units: m
group: Q
visual_asset_id: vtol_land_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# QuadPlane RTL Altitude (Q_RTL_ALT)

## Description
`Q_RTL_ALT` sets the "Safe Height" for the final VTOL descent.

When the plane returns home, it will transition to VTOL mode and climb or descend to this altitude before starting the final vertical landing.

## Tuning & Behavior
*   **Default Value:** 15 meters.
*   **Recommendation:** Set high enough to clear any trees or obstacles near your landing zone.