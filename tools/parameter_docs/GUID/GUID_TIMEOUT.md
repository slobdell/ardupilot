---
layout: parameter
name: GUID_TIMEOUT
display_name: Guided mode timeout
description: Timeout in seconds for Guided mode offboard control.
default_value: 3.0
range: 0 10
units: s
group: GUID
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduCopter/Parameters.cpp
---

# Guided mode timeout (GUID_TIMEOUT)

## Description
Defines the maximum time the flight controller will wait for a new offboard control message (e.g., from a companion computer) before taking safety action.