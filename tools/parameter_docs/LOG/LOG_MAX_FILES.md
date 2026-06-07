---
layout: parameter
name: LOG_MAX_FILES
display_name: Maximum number of log files
description: The maximum number of log files to keep on the SD card before overwriting the oldest one.
default_value: 500
range: 2 500
units: 
group: LOG
visual_asset_id: sd_card_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Logger/AP_Logger.cpp#L198
---

# Maximum number of log files (LOG_MAX_FILES)

## Description
`LOG_MAX_FILES` limits the number of files in the `/LOGS` directory.

*   **Default (500):** ArduPilot keeps up to 500 flights.
*   **Safety:** This prevents directory fragmentation and slow boot times caused by having thousands of tiny files on the SD card.