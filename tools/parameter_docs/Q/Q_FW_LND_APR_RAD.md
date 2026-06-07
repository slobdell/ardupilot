---
layout: parameter
name: Q_FW_LND_APR_RAD
display_name: QuadPlane Fixed-Wing Landing Approach Radius
description: The radius (in meters) of the turn onto the final approach leg for a fixed-wing landing.
default_value: 0
range: 0 1000
units: m
group: Q
visual_asset_id: vtol_land_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# QuadPlane Fixed-Wing Landing Approach Radius (Q_FW_LND_APR_RAD)

## Description
`Q_FW_LND_APR_RAD` defines the tightness of the turn when lining up for a runway landing.

If set to 0, it uses `WP_LOITER_RAD`.

## Tuning & Behavior
*   **Default Value:** 0.