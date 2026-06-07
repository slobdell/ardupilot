---
layout: parameter
name: BRD_VBUS_MIN
display_name: Autopilot board voltage requirement
description: Minimum voltage on the autopilot power rail to allow the aircraft to arm. 0 to disable the check.
default_value: 4.3
range: 4.0 5.5
units: V
group: BRD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_BoardConfig/AP_BoardConfig.cpp
---

# Autopilot board voltage requirement (BRD_VBUS_MIN)

## Description
Pre-arm safety threshold for the flight controller's internal supply voltage. Arming is blocked if the input voltage is too low, indicating a potentially unreliable power source.