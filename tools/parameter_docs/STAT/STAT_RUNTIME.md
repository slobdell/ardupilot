---
layout: parameter
name: STAT_RUNTIME
display_name: Total RunTime
description: Total time autopilot has run (seconds).
default_value: 0
range: 
units: s
group: STAT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Stats/AP_Stats.cpp#L32
---

# STAT_RUNTIME: Total RunTime

## Description
Total time autopilot has run.

## Values
- **Units:** s
- **Default:** 0

## Description
This parameter tracks the total cumulative uptime of the flight controller, regardless of whether it was flying or just sitting on the bench.

- **Function:** Increments continuously while the board is powered on.
- **Persistence:** Saved to storage and persists across reboots.
- **Usage:** Can be used to estimate total system life or debug "time since first power on" issues.

