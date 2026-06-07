---
layout: parameter
name: CAN_D1_PC_ESC_RT
display_name: PiccoloCAN ESC Output Rate (Driver 1)
description: The frequency (in Hz) at which ESC command messages are transmitted over the PiccoloCAN bus.
default_value: 50
range: 1 500
units: Hz
group: CAN
visual_asset_id: can_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_PiccoloCAN/AP_PiccoloCAN.cpp#L40
---

# PiccoloCAN ESC Output Rate (CAN_D1_PC_ESC_RT)

## Description
`CAN_D1_PC_ESC_RT` sets the update speed for motors connected via the PiccoloCAN protocol.

*   **Higher Value (400-500Hz):** Provides faster motor response and better flight stability, similar to high-speed DShot.
*   **Lower Value (50Hz):** Standard update rate.

## Tuning & Behavior
*   **Recommendation:** Set to **400** for high-performance multirotors. Ensure your PiccoloCAN ESCs support the requested frequency.
