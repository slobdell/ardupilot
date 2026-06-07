---
layout: parameter
name: STAT_FLTTIME
display_name: Total FlightTime
description: Total FlightTime (seconds).
default_value: 0
range: 
units: s
group: STAT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Stats/AP_Stats.cpp#L24
---

# STAT_FLTTIME: Total FlightTime

## Description
Total FlightTime (seconds).

## Values
- **Units:** s
- **Default:** 0

## Description
This parameter tracks the cumulative time the vehicle has been "flying" (armed and active).

- **Function:** It increments whenever the vehicle is armed and in a flying state.
- **Persistence:** This value is saved to storage and persists across reboots.
- **Maintenance:** Useful for scheduling maintenance intervals (e.g., motor bearing checks every 50 hours).

