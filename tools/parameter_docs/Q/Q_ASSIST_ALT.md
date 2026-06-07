---
layout: parameter
name: Q_ASSIST_ALT
display_name: QuadPlane Assist Altitude
description: The altitude (in meters) below which QuadPlane assistance is automatically enabled to prevent stalling.
default_value: 0
range: 0 100
units: m
group: Q
visual_asset_id: vtol_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# QuadPlane Assist Altitude (Q_ASSIST_ALT)

## Description
`Q_ASSIST_ALT` is a safety net for landing.

If the plane drops below this altitude (e.g., 30 meters), the VTOL motors will "wake up" and assist if the airspeed drops too low. This prevents the plane from stalling near the ground during a fixed-wing approach.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled).
*   **Recommendation:** Set to **30m to 50m** if you are flying manual approaches and want a safety backup.