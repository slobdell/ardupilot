---
layout: parameter
name: OA_DB_ALT_MIN
display_name: OADatabase Min Altitude
description: The minimum altitude (in meters) above home before the autopilot starts recording obstacles into the database.
default_value: 0
range: 0 5
units: m
group: OA
visual_asset_id: avoid_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_Avoidance/AP_OADatabase.cpp#L101
---

# OADatabase Min Altitude (OA_DB_ALT_MIN)

## Description
`OA_DB_ALT_MIN` prevents the drone from trying to "Avoid" the ground or grass during takeoff and landing.

If set to 1.0, the drone will ignore all sensor detections until it is more than 1 meter high. This prevents false detections from long grass or uneven terrain from triggering a panicked maneuver while the drone is still close to its launch point.