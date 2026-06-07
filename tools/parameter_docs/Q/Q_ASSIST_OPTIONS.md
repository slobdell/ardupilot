---
layout: parameter
name: Q_ASSIST_OPTIONS
display_name: QuadPlane Assist Options
description: A bitmask of options for the QuadPlane assistance (stall prevention) feature.
default_value: 0
range: 0 4294967295
units: 
group: Q
visual_asset_id: vtol_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# QuadPlane Assist Options (Q_ASSIST_OPTIONS)

## Description
`Q_ASSIST_OPTIONS` toggles advanced behaviors for the VTOL safety net.

## Tuning & Behavior
*   **Default Value:** 0.
*   **Bit 0:** Disable assistance during fixed-wing takeoff.
*   **Bit 1:** Disable assistance during fixed-wing landing.
*   **Bit 2:** Enable assistance even in Manual/Stabilize modes (Standard is only for assisted modes like FBWA).