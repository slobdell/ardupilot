---
layout: parameter
name: LAND_DS_ARSP_MAX
display_name: Deepstall Enabled Airspeed
description: The maximum airspeed (in m/s) below which the deepstall steering controller is allowed to take full control.
default_value: 15.0
range: 5 20
units: m/s
group: LAND
visual_asset_id: deepstall_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Landing/AP_Landing_Deepstall.cpp#L83
---

# Deepstall Enabled Airspeed (LAND_DS_ARSP_MAX)

## Description
`LAND_DS_ARSP_MAX` defines the "Entry Speed" for the deep stall maneuver.

When the plane slows down past this speed, the deep stall controller wakes up and starts blending in its own steering logic.

## Tuning & Behavior
*   **Default Value:** 15.0 m/s.
*   **Recommendation:** Set slightly above your stall speed.