---
layout: parameter
name: FS_LONG_TIMEOUT
display_name: Long Failsafe Timeout
description: The time (in seconds) of lost RC signal before a Long Failsafe is triggered.
default_value: 5.0
range: 2 120
units: s
group: FS
visual_asset_id: failsafe_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduPlane/Parameters.cpp#L471
---

# Long Failsafe Timeout (FS_LONG_TIMEOUT)

## Description
`FS_LONG_TIMEOUT` sets the duration of signal loss required to trigger the [FS_LONG_ACTN](FS_LONG_ACTN.html).

*   **Standard Setting:** 5 seconds.
*   **Long Range:** If you are flying at the extreme edge of your radio range where "link blips" are common, you may increase this to **10s** or **20s** to avoid unnecessary RTLs.

## Tuning & Behavior
*   **Default:** 5.0.
*   **Warning:** Increasing this value means the drone will continue flying its last known command for longer without pilot input. Use with caution.
