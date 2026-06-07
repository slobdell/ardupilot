---
layout: parameter
name: LAND_DS_L1
display_name: Deepstall L1 Period
description: The period (in seconds) for the L1 navigation controller during deepstall.
default_value: 30.0
range: 5 50
units: s
group: LAND
visual_asset_id: deepstall_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Landing/AP_Landing_Deepstall.cpp#L97
---

# Deepstall L1 Period (LAND_DS_L1)

## Description
`LAND_DS_L1` defines how aggressively the plane tries to return to the path.

A shorter period means the plane will turn sharper to get back on track.

## Tuning & Behavior
*   **Default Value:** 30.0 s.
*   **Recommendation:** Since deep stall happens slowly, a long period like 30s is usually appropriate.