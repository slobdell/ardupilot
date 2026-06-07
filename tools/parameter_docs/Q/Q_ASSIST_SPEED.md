---
layout: parameter
name: Q_ASSIST_SPEED
display_name: QuadPlane Assist Speed
description: The airspeed (in m/s) below which QuadPlane assistance is automatically enabled.
default_value: 0
range: 0 30
units: m/s
group: Q
visual_asset_id: vtol_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# QuadPlane Assist Speed (Q_ASSIST_SPEED)

## Description
`Q_ASSIST_SPEED` is the primary stall prevention mechanism for QuadPlanes.

If the airspeed drops below this value while in a fixed-wing mode (like FBWA or AUTO), the VTOL motors will spin up to provide lift and thrust, preventing a stall.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled).
*   **Recommendation:** Set to **1-2 m/s above your stall speed**.
*   **Example:** If your plane stalls at 10 m/s, set `Q_ASSIST_SPEED` to **12**.
