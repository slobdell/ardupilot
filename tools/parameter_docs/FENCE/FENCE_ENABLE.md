---
layout: parameter
name: FENCE_ENABLE
display_name: Fence enable/disable
description: Allows you to enable (1) or disable (0) the fence functionality.
default_value: 0
range: 0 1
units: 
group: FENCE
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AC_Fence/AC_Fence.cpp
---

# Fence enable/disable (FENCE_ENABLE)

## Description
Master power switch for the geofence system. When enabled, the vehicle will monitor its position against defined boundaries and take automatic action if they are breached.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled)
*   **Requires at least one fence type (e.g., Circle or Polygon) to be configured in FENCE_TYPE.**
