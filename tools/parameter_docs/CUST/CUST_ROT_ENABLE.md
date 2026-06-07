---
layout: parameter
name: CUST_ROT_ENABLE
display_name: Enable Custom rotations
description: Enables the use of custom Euler-angle rotations for sensors or the flight controller itself.
default_value: 0
range: 0 1
units: 
group: CUST
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_CustomRotations/AP_CustomRotations.cpp
---

# Enable Custom rotations (CUST_ROT_ENABLE)

## Description
Master switch for the custom rotations library. When enabled, it allows sensors (like compasses or IMUs) to use a specific user-defined rotation (Custom 1 or Custom 2) instead of the standard 45/90 degree increments.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled)
*   **Requires reboot to take effect.**