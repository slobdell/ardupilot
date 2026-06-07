---
layout: parameter
name: AXIS_MASK
display_name: Custom Controller Axis Mask
description: Bitmask of axes for which the custom controller should be active.
default_value: 0
range: 
units: 
group: AXIS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AC_CustomControl/AC_CustomControl.cpp
---

# Custom Controller Axis Mask (AXIS_MASK)

## Description
Defines which flight axes (Roll, Pitch, Yaw) are managed by a custom user-defined controller instead of the standard ArduPilot attitude control logic.

## Tuning & Behavior
*   **Default Value:** 0 (Standard controllers active on all axes)
*   **Bitmask:**
    *   Bit 0: Roll
    *   Bit 1: Pitch
    *   Bit 2: Yaw