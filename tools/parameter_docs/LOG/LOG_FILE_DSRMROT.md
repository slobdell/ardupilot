---
layout: parameter
name: LOG_FILE_DSRMROT
display_name: Stop logging to current file on disarm
description: Controls whether a new log file is started every time the drone is armed.
default_value: 0
range: 0 1
units: 
group: LOG
visual_asset_id: logging_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Logger/AP_Logger.cpp#L141
---

# Stop logging to current file on disarm (LOG_FILE_DSRMROT)

## Description
`LOG_FILE_DSRMROT` helps organize your flight logs.

*   **0 (Default):** One log file per power cycle. If you land, disarm, and re-arm without unplugging the battery, everything is saved in one big file.
*   **1 (Rotate):** Every flight (each Arm/Disarm cycle) gets its own individual `.BIN` file. This makes it much easier to find the specific flight you are looking for in a long day of testing.

## Tuning & Behavior
*   **Recommendation:** Set to **1** for easier post-flight analysis.
*   **Note:** If [LOG_DISARMED](LOG_DISARMED.html) is enabled, setting this to 1 will immediately start a new log the moment you land.