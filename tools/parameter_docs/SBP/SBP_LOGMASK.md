---
layout: parameter
name: SBP_LOGMASK
display_name: Swift Binary Protocol Logging Mask
description: Masked with the SBP msg_type field to determine whether SBR1/SBR2 data is logged.
default_value: -256
range: 
units: 
group: SBP
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_GPS/AP_GPS.cpp#L181
---

# SBP_LOGMASK: Swift Binary Protocol Logging Mask

## Description
This parameter acts as a filter for logging Swift Binary Protocol (SBP) messages from Swift Navigation GPS modules (like the Piksi Multi) to the autopilot's DataFlash logs.

## Values
| Value | Meaning |
| :--- | :--- |
| 0 | None (0x0000) - No SBP messages logged |
| -1 | All (0xFFFF) - All SBP messages logged |
| -256 | External only (0xFF00) - Only log messages originating from external sources |

- **Default:** -256

## Description
For users of Swift Navigation RTK GPS systems, `SBP_LOGMASK` controls the verbosity of the raw GPS data stream captured in the logs.

- **Function:** It performs a bitwise AND between this mask and the SBP message type ID. If the result is non-zero, the message is logged as `SBR1` or `SBR2` packets.
- **Diagnostic Use:** If you are having trouble with RTK fix stability or GPS timing, setting this to **-1** captures everything for detailed analysis by Swift Navigation support, but it will significantly increase the log file size.

