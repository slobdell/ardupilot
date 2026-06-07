---
layout: parameter
name: LOG_BACKEND_TYPE
display_name: AP_Logger Backend Storage type
description: Bitmask to select which storage backends are used for DataFlash logging.
default_value: 1
range: 0 7
units: 
group: LOG
visual_asset_id: logging_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Logger/AP_Logger.cpp#L97
---

# AP_Logger Backend Storage type (LOG_BACKEND_TYPE)

## Description
`LOG_BACKEND_TYPE` determines where your flight data is physically stored.

Most flight controllers have an SD card, but some specialized hardware might use internal flash chips (Block) or send the log data live over a telemetry radio (MAVLink).

*   **Bit 0 (1): File.** Save logs to the SD card (Standard).
*   **Bit 1 (2): MAVLink.** Send log data live to your Ground Station. (Requires high bandwidth link like WiFi/LTE).
*   **Bit 2 (4): Block.** Save logs to the internal onboard dataflash chip (if available).

## Tuning & Behavior
*   **Default Value:** Usually 1 (File).
*   **Safety:** You can enable multiple backends simultaneously (e.g., set to 5 for File + Block).
*   **Reboot Required:** Yes.