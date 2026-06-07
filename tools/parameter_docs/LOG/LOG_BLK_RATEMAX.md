---
layout: parameter
name: LOG_BLK_RATEMAX
display_name: Maximum logging rate for block backend
description: Limits the rate (in Hz) at which streaming log messages are written to the internal block storage.
default_value: 0
range: 0 1000
units: Hz
group: LOG
visual_asset_id: logging_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Logger/AP_Logger.cpp#L182
---

# Maximum logging rate for block backend (LOG_BLK_RATEMAX)

## Description
`LOG_BLK_RATEMAX` sets a speed limit for data being written to the onboard flash chip.

Internal flash chips often have limited capacity and write cycles. By setting a rate limit (e.g., 50Hz), you can ensure you capture enough data for tuning while preventing the chip from filling up too quickly during long flights.

*   **0:** No limit.