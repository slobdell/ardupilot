---
layout: parameter
name: BRD_RADIO_TELEM
display_name: Enable telemetry
description: If enabled, telemetry packets will be sent over the direct attached radio.
default_value: 0
range: 0 1
units: 
group: BRD_RADIO
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Radio/AP_Radio.cpp
---

# Enable telemetry (BRD_RADIO_TELEM)

## Description
Enables bidirectional telemetry communication over the internal radio link.