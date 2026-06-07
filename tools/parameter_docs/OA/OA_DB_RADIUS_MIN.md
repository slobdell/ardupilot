---
layout: parameter
name: OA_DB_RADIUS_MIN
display_name: OADatabase Minimum Radius
description: The minimum physical size (radius in meters) assigned to any detected obstacle.
default_value: 0.01
range: 0 10
units: m
group: OA
visual_asset_id: avoid_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_Avoidance/AP_OADatabase.cpp#L85
---

# OADatabase Minimum Radius (OA_DB_RADIUS_MIN)

## Description
`OA_DB_RADIUS_MIN` ensures that every detected point is treated as a solid object with at least some physical dimension. Even if the Lidar beam is perfectly narrow, ArduPilot will assume the obstacle has at least this much radius to provide a safety margin for the drone's frame.