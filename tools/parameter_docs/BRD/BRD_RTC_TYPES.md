---
layout: parameter
name: BRD_RTC_TYPES
display_name: Allowed RTC types
description: Bitmask of allowed Real Time Clock types.
default_value: 1
range: 
units: 
group: BRD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_RTC/AP_RTC.cpp
---

# Allowed RTC types (BRD_RTC_TYPES)

## Description
Specifies which sources (GPS, Internal, System) are allowed to set the vehicle's Real Time Clock.