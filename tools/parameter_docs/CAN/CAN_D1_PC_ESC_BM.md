---
layout: parameter
name: CAN_D1_PC_ESC_BM
display_name: PiccoloCAN ESC Bitmask
description: A bitmask of output channels to send to PiccoloCAN ESCs.
default_value: 0
range: 0 4294967295
units: 
group: CAN
visual_asset_id: can_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_PiccoloCAN/AP_PiccoloCAN.cpp#L25
---

# PiccoloCAN ESC Bitmask (CAN_D1_PC_ESC_BM)

## Description
`CAN_D1_PC_ESC_BM` identifies which motor channels use the PiccoloCAN protocol.

PiccoloCAN is a specialized CAN protocol used primarily in industrial and long-endurance airframes. This bitmask tells ArduPilot which of the internal motor outputs should be translated into PiccoloCAN commands on this driver.

## Tuning & Behavior
*   **Default Value:** 0.