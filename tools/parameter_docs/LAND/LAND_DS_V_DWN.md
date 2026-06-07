---
layout: parameter
name: LAND_DS_V_DWN
display_name: Deepstall Sink Rate
description: The expected downward velocity (sink rate in m/s) of the aircraft while in a deepstall.
default_value: 2
range: 0 20
units: m/s
group: LAND
visual_asset_id: deepstall_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Landing/AP_Landing_Deepstall.cpp#L61
---

# Deepstall Sink Rate (LAND_DS_V_DWN)

## Description
`LAND_DS_V_DWN` defines how fast the plane falls once it has stalled.

## Tuning & Behavior
*   **Default Value:** 2.0 m/s.
*   **Recommendation:** High-drag planes (large wings) will fall slower. High-weight planes will fall faster.