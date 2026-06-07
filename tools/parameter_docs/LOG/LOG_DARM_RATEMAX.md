---
layout: parameter
name: LOG_DARM_RATEMAX
display_name: Maximum logging rate when disarmed
description: Limits the rate (in Hz) at which streaming log messages are written while the drone is disarmed.
default_value: 0
range: 0 1000
units: Hz
group: LOG
visual_asset_id: logging_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Logger/AP_Logger.cpp#L190
---

# Maximum logging rate when disarmed (LOG_DARM_RATEMAX)

## Description
`LOG_DARM_RATEMAX` allows you to save SD card space by recording at a lower fidelity while sitting on the ground.

While you are flying, you need high-speed data (400Hz+) to analyze vibrations and PIDs. On the ground, you usually only need a slow update (e.g. 5Hz) to monitor GPS health or battery status.

*   **0:** Use the normal backend rate limits.
*   **10:** Force 10Hz logging while disarmed.