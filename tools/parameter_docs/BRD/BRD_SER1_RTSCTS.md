---
layout: parameter
name: BRD_SER1_RTSCTS
display_name: Serial 1 flow control
description: Enable flow control on serial 1 (telemetry 1).
default_value: 2
range: 0 3
units: 
group: BRD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_BoardConfig/AP_BoardConfig.cpp
---

# Serial 1 flow control (BRD_SER1_RTSCTS)

## Description
Enables hardware flow control (RTS/CTS) for the first telemetry port. This prevents data loss during high-bandwidth telemetry streaming.

## Tuning & Behavior
*   **Default Value:** 2 (Auto)
*   **Values:** 0:Disabled, 1:Enabled, 2:Auto, 3:RS-485