---
layout: parameter
name: LAND_DS_ARSP_MIN
display_name: Deepstall Minimum Derating Airspeed
description: The airspeed (in m/s) below which the deepstall controller has 100% authority.
default_value: 10.0
range: 5 20
units: m/s
group: LAND
visual_asset_id: deepstall_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Landing/AP_Landing_Deepstall.cpp#L90
---

# Deepstall Minimum Derating Airspeed (LAND_DS_ARSP_MIN)

## Description
`LAND_DS_ARSP_MIN` defines the "Fully Stalled" speed.

Between `ARSP_MAX` and `ARSP_MIN`, the control authority is mixed. Below `ARSP_MIN`, the deep stall controller is in full command.

## Tuning & Behavior
*   **Default Value:** 10.0 m/s.
*   **Recommendation:** Set to your deep-stall vertical descent speed converted to forward speed equivalent, or just below stall speed.