---
layout: parameter
name: LOG_FILE_BUFSIZE
display_name: Logging File buffer size max
description: The amount of RAM (in kilobytes) dedicated to buffering log data before it is written to the SD card.
default_value: 200
range: 4 200
units: kB
group: LOG
visual_asset_id: logging_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Logger/AP_Logger.cpp#L123
---

# Logging File buffer size max (LOG_FILE_BUFSIZE)

## Description
`LOG_FILE_BUFSIZE` helps prevent "Gaps" in your logs.

SD cards are sometimes slow to write. This parameter creates a "Waiting Area" (buffer) in the flight controller's RAM. Data is collected here and then written to the card in one big burst. A larger buffer can handle slower SD cards without losing data.

## Tuning & Behavior
*   **Default Value:** 200 KB (on high-end boards like Cube Orange).
*   **Recommendation:** If you see "Log: GAP" messages in your log files, increase this value to its maximum (200).