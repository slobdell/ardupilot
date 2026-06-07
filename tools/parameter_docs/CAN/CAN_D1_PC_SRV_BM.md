---
layout: parameter
name: CAN_D1_PC_SRV_BM
display_name: PiccoloCAN Servo Bitmask (Driver 1)
description: A bitmask defining which logical servo channels are transmitted as PiccoloCAN servo commands.
default_value: 65535
range: 0 65535
units: 
group: CAN
visual_asset_id: can_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_PiccoloCAN/AP_PiccoloCAN.cpp#L41
---

# PiccoloCAN Servo Bitmask (CAN_D1_PC_SRV_BM)

## Description
`CAN_D1_PC_SRV_BM` selects which servos on the drone are controlled via the PiccoloCAN network.

*   **Bit 0 (1):** Servo 1
*   **Bit 1 (2):** Servo 2
*   ...

## Tuning & Behavior
*   **Default Value:** 65535 (All 16 channels enabled).
