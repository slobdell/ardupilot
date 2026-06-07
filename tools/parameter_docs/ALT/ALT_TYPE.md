---
layout: parameter
name: ALT_TYPE
display_name: Follow Altitude Type
description: Altitude reference type for Follow mode.
default_value: 0
range: 
units: 
group: ALT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Follow/AP_Follow.cpp
---

# Follow Altitude Type (ALT_TYPE)

## Description
Specifies the altitude reference frame used when in Follow mode.

## Tuning & Behavior
*   **Default Value:** 0 (AMSL)
*   **Values:** 0:AMSL (Above Mean Sea Level), 1:Relative (Above Home)