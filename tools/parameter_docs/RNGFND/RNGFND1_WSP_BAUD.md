---
layout: parameter
name: RNGFND1_WSP_BAUD
display_name: Wasp-LRF Baud Rate
description: Selects the serial communication speed for the Wasp-LRF sensor.
default_value: 0
range: 0 1
units: 
group: RNGFND
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_RangeFinder/AP_RangeFinder_Wasp.cpp#L66
---

# Wasp-LRF Baud Rate (RNGFND1_WSP_BAUD)

## Description
`RNGFND1_WSP_BAUD` sets the UART speed for the **Wasp-LRF** laser sensor.

*   **0: Low Speed (115200).** Standard for most telemetry ports.
*   **1: High Speed (921600).** Required if you are using extremely high update frequencies (>1000 Hz).