---
layout: parameter
name: GPS_SBP_LOGMASK
display_name: Swift Binary Protocol Logging Mask
description: A bitmask used to filter which SBP message types are recorded in the system log.
default_value: -256
range: 
units: 
group: GPS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_GPS/AP_GPS.cpp#L181
---

# Swift Binary Protocol Logging Mask (GPS_SBP_LOGMASK)

## Description
`GPS_SBP_LOGMASK` is a diagnostic tool for **Swift Navigation** GPS receivers (Piksi/Duro).

These receivers use the Swift Binary Protocol (SBP). This mask allows developers and advanced users to filter exactly which data types from the receiver are recorded in the ArduPilot onboard logs. This helps manage log size while capturing essential troubleshooting information.

## Tuning & Behavior
*   **Default:** -256 (0xFF00).
*   **Usage:** For most users, leave at the default value. If instructed by Swift Navigation support or an ArduPilot developer, you may need to change this to capture specific low-level GNSS data.
*   **Impact:** Setting this to record high-rate data will significantly increase the CPU load and SD card bandwidth usage.