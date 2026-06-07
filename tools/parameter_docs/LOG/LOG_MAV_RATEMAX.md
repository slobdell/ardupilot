---
layout: parameter
name: LOG_MAV_RATEMAX
display_name: Maximum logging rate for mavlink backend
description: Limits the rate (in Hz) at which log messages are sent live over the MAVLink telemetry link.
default_value: 0
range: 0 1000
units: Hz
group: LOG
visual_asset_id: logging_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Logger/AP_Logger.cpp#L178
---

# Maximum logging rate for mavlink backend (LOG_MAV_RATEMAX)

## Description
`LOG_MAV_RATEMAX` prevents live logging from choking your telemetry link.

Live MAVLink logging is very bandwidth intensive. If you are using a 915MHz SiK radio, you should set this to a very low value (e.g. 1Hz) or disable the MAVLink backend entirely. If you are using a high-speed WiFi link, you can set it higher.

## Tuning & Behavior
*   **Default Value:** 0 (Unlimited).
*   **Recommendation:** Usually left at **0** because the MAVLink backend is disabled by default in `LOG_BACKEND_TYPE`.