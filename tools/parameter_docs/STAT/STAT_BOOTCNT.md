---
layout: parameter
title: STAT_BOOTCNT
name: Boot Count
group: STAT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Stats/AP_Stats.cpp#L16
---

# STAT_BOOTCNT: Boot Count

## Description
Number of times board has been booted.

## Values
- **Default:** 0

## Description
This parameter serves as a persistent odometer for the flight controller hardware.

- **Function:** Every time the board powers up or reboots, this counter increments by 1.
- **Usage:** Useful for tracking the age of the board and identifying if uncommanded reboots (watchdog resets) have occurred during a mission or between flights.
- **Reset:** Can be reset by setting `STAT_RESET` to 0.

