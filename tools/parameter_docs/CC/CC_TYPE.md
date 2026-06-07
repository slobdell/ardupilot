---
layout: parameter
name: CC_TYPE
display_name: Custom control type
description: Specifies the type of custom attitude controller to be used.
default_value: 0
range: 
units: 
group: CC
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AC_CustomControl/AC_CustomControl.cpp
---

# Custom control type (CC_TYPE)

## Description
Enables the custom attitude control module and selects the backend implementation (e.g., a simple template or a PID-based controller).

## Tuning & Behavior
*   **Default Value:** 0 (None)
*   **Values:** 0:None, 1:Empty (Template), 2:PID
*   **Requires reboot to initialize the selected controller.**