---
layout: parameter
name: LOG_FILE_TIMEOUT
display_name: Timeout before giving up on file writes
description: The time (in seconds) the autopilot waits for a successful SD card write before giving up and stopping the log.
default_value: 5
range: 1 60
units: s
group: LOG
visual_asset_id: sd_card_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Logger/AP_Logger.cpp#L155
---

# Timeout before giving up on file writes (LOG_FILE_TIMEOUT)

## Description
`LOG_FILE_TIMEOUT` detects failing SD cards.

If your SD card is slow or damaged, it might "hang" during a write operation. If it stays unresponsive for longer than this duration, ArduPilot declares the log as failed and stops recording to protect the main flight control CPU from waiting indefinitely.

## Tuning & Behavior
*   **Default Value:** 5 seconds.
*   **Safety:** Do not set this too high. An unresponsive SD card can eventually cause "Internal Error 0x800" (Main Loop Slow) if the system spends too much time waiting for it.