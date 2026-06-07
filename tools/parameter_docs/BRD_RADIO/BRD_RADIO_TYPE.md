---
layout: parameter
name: BRD_RADIO_TYPE
display_name: Radio type
description: Enables support for direct attached radio receivers.
default_value: 0
range: 
units: 
group: BRD_RADIO
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Radio/AP_Radio.cpp
---

# Radio type (BRD_RADIO_TYPE)

## Description
Enables support for built-in or direct-attached radio receivers (e.g., on SkyViper vehicles).

## Tuning & Behavior
*   **Default Value:** 0 (None)
*   **Values:** 0:None, 1:CYRF6936, 2:CC2500, 3:BK2425
*   **Requires reboot to take effect.**
