---
layout: parameter
name: BRD_RADIO_FCCTST
display_name: FCC test mode
description: Puts the radio into continuous transmission mode for FCC compliance testing.
default_value: 0
range: 0 6
units: 
group: BRD_RADIO
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Radio/AP_Radio.cpp
---

# FCC test mode (BRD_RADIO_FCCTST)

## Description
Puts the internal radio into a specialized continuous-transmit state required for regulatory certification.
*   **WARNING: The radio will not process RC inputs while in this mode.**
