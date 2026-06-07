---
layout: parameter
name: CC_AXIS_MASK
display_name: Custom Controller bitmask
description: Bitmask selecting which flight axes (Roll, Pitch, Yaw) the custom controller should manage.
default_value: 0
range: 
units: 
group: CC
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AC_CustomControl/AC_CustomControl.cpp
---

# Custom Controller bitmask (CC_AXIS_MASK)

## Description
Defines the specific axes that are handed over to the custom controller. When an axis bit is set, the standard ArduPilot attitude controller for that axis is bypassed.

## Tuning & Behavior
*   **Default Value:** 0
*   **Bitmask:**
    *   Bit 0: Roll
    *   Bit 1: Pitch
    *   Bit 2: Yaw