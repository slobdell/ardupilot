---
layout: parameter
name: FENCE_OPTIONS
display_name: Fence options
description: Bitmask for advanced geofence behaviors.
default_value: 0
range: 
units: 
group: FENCE
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AC_Fence/AC_Fence.cpp
---

# Fence options (FENCE_OPTIONS)

## Description
Configuration bitmask for tailoring fence logic, such as preventing flight mode changes until a breach is cleared.

## Tuning & Behavior
*   **Default Value:** 0
*   **Bitmask:**
    *   Bit 0: Disable mode change following action until breach cleared
    *   Bit 1: Allow union of inclusion areas