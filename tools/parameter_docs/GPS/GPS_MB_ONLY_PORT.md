---
layout: parameter
name: GPS_MB_ONLY_PORT
display_name: Moving Baseline CAN Port Selection
description: Selects a dedicated CAN port for transmitting GPS Moving Baseline (RTK) data.
default_value: 0
range: 0 2
units: 
group: GPS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/Tools/AP_Periph/Parameters.cpp#L249
---

# Moving Baseline CAN Port Selection (GPS_MB_ONLY_PORT)

## Description
`GPS_MB_ONLY_PORT` is used when setting up a **Moving Baseline** GPS system (where two GPS units work together to calculate the drone's heading without a compass).

This parameter tells the autopilot (or peripheral node) which CAN port should be used to send the RTK correction data between the two GPS units. Using a dedicated port ensures that these high-frequency corrections don't interfere with other vital telemetry on the main CAN bus.

*   **0: Auto.**
*   **1: CAN Port 1.**
*   **2: CAN Port 2.**

## Tuning & Behavior
*   **Default:** 0.
*   **Usage:** Only used on **AP_Periph** CAN nodes when configuring an integrated dual-GPS system over CAN.