---
layout: parameter
name: Q_WVANE_ANG_MIN
display_name: QuadPlane Weathervane Min Angle
description: The minimum angle error (in degrees) required to activate weathervaning.
default_value: 1
range: 0 10
units: deg
group: Q
visual_asset_id: vtol_weathervane_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# QuadPlane Weathervane Min Angle (Q_WVANE_ANG_MIN)

## Description
`Q_WVANE_ANG_MIN` creates a "Deadband" for the weathervane logic.

If the wind is only 2 degrees off the nose, you probably don't want the motors to spin up to correct it. This parameter prevents "Hunting" in variable winds.

## Tuning & Behavior
*   **Default Value:** 1 degree.