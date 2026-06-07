---
layout: parameter
name: LOG_FILE_MB_FREE
display_name: Min free MB on SD card
description: The minimum amount of free space (in Megabytes) to maintain on the SD card by deleting the oldest logs.
default_value: 500
range: 10 1000
units: MB
group: LOG
visual_asset_id: sd_card_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Logger/AP_Logger.cpp#L162
---

# Min free MB on SD card (LOG_FILE_MB_FREE)

## Description
`LOG_FILE_MB_FREE` is an "Auto-Cleanup" setting.

To prevent the SD card from becoming completely full (which causes write errors and potentially crashes), ArduPilot automatically deletes your oldest log files when the free space drops below this limit.

*   **500 (Default):** Maintain at least 500MB of free space.

## Tuning & Behavior
*   **Recommendation:** Set this to be larger than your largest typical flight log (e.g. if you fly 1-hour missions that generate 200MB logs, 500MB is a safe limit).