---
layout: parameter
name: BRD_RADIO_DISCRC
display_name: Internal Radio Disable RX CRC
description: Disables the Cyclical Redundancy Check (CRC) for incoming radio packets (Debug Only).
default_value: 0
range: 0 1
units: 
group: BRD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Radio/AP_Radio.cpp#L45
---

# Internal Radio Disable RX CRC (BRD_RADIO_DISCRC)

## Description
`BRD_RADIO_DISCRC` is a low-level developer tool for debugging integrated SPI radios.

CRC is a mathematical check that ensures a packet wasn't corrupted during its flight through the air. Normally, if a packet fails this check, it is thrown away. By disabling this check, the autopilot will attempt to process *every* signal it receives, even if it is garbage.

*   **0: Enabled (Safe/Default).** Corrupt packets are ignored.
*   **1: Disabled (DANGEROUS).** Corrupt packets are accepted.

## Tuning & Behavior
*   **Warning:** **NEVER enable this for flight.** Accepting corrupt packets can lead to "Phantom Stick Movements" where the drone suddenly receives a command to full throttle or hard roll due to a bit-flip in the air. 
*   **Usage:** Only used on the bench to see if a radio link is "almost" working but failing due to slight noise issues.