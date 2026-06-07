---
layout: parameter
name: LOG_FILE_RATEMAX
display_name: Maximum logging rate for file backend
description: Limits the rate (in Hz) at which log messages are written to the SD card.
default_value: 0
range: 0 1000
units: Hz
group: LOG
visual_asset_id: logging_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Logger/AP_Logger.cpp#L170
---

# Maximum logging rate for file backend (LOG_FILE_RATEMAX)

## Description
`LOG_FILE_RATEMAX` prevents your SD card from being overwhelmed by too much data.

High-speed logs (like raw IMU or fast attitude) can generate massive amounts of traffic. If your SD card is slow, the drone might experience "I/O Wait" stutters. This parameter sets a limit on the logging frequency.

*   **0 (Default):** No limit. Record everything as fast as the system demands.
*   **100:** Limit streaming messages to 100 Hz.

## Tuning & Behavior
*   **Recommendation:** Leave at **0** unless you see "Log dropped" errors in your GCS or experience flight performance issues due to slow storage media.
