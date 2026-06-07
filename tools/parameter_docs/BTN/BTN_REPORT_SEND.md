---
layout: parameter
name: BTN_REPORT_SEND
display_name: Report send time
description: The duration in seconds that a BUTTON_CHANGE report is repeatedly sent to the GCS regarding a button changing state.
default_value: 10
range: 0 3600
units: s
group: BTN
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Button/AP_Button.cpp
---

# Report send time (BTN_REPORT_SEND)

## Description
Determines for how long the flight controller will continue to broadcast a button state change message over MAVLink after the event occurs.