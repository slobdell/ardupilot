---
layout: parameter
name: LAND_DS_APP_EXT
display_name: Deepstall Approach Extension
description: The horizontal distance (in meters) the aircraft will fly on its approach path before triggering the stall.
default_value: 50
range: 10 200
units: m
group: LAND
visual_asset_id: deepstall_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Landing/AP_Landing_Deepstall.cpp#L48
---

# Deepstall Approach Extension (LAND_DS_APP_EXT)

## Description
`LAND_DS_APP_EXT` adds a "Straightaway" to the deepstall landing path.

Before the plane enters a stall, it needs to be perfectly lined up with the target and flying level. This parameter ensures the plane flies in a straight line for at least this distance before pulling the elevator up to stall.

## Tuning & Behavior
*   **Default Value:** 50 meters.
*   **Recommendation:** Increase to **100m** if your plane has high inertia and needs more time to settle onto its final heading.