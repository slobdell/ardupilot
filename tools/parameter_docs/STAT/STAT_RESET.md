---
layout: parameter
name: STAT_RESET
display_name: Statistics Reset Time
description: Seconds since January 1st 2016 (Unix epoch+1451606400) since statistics reset (set to 0 to reset statistics, other set values will be ignored).
default_value: 1
range: 
units: s
group: STAT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Stats/AP_Stats.cpp#L40
---

# STAT_RESET: Statistics Reset Time

## Description
Seconds since January 1st 2016 (Unix epoch+1451606400) since statistics reset (set to 0 to reset statistics, other set values will be ignored).

## Values
- **Units:** s
- **Default:** 1

## Description
This parameter holds the timestamp of the last time the flight statistics (`STAT_BOOTCNT`, `STAT_FLTTIME`, `STAT_RUNTIME`) were reset.

- **How to Reset:** To clear all accumulated statistics, manually set this parameter to **0**. The autopilot will then reset the counters and update this parameter to the current system time.
- **Format:** The value is the number of seconds since Jan 1st, 2016.

