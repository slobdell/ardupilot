---
layout: parameter
name: CIRCLE_OPTIONS
display_name: Circle options
description: Bitmask of options for Circle mode behavior.
default_value: 1
range: 
units: 
group: CIRCLE
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AC_WPNav/AC_Circle.cpp
---

# Circle options (CIRCLE_OPTIONS)

## Description
Configuration bitmask for tailoring the vehicle's orientation and starting logic during Circle mode.

## Tuning & Behavior
*   **Default Value:** 1
*   **Bitmask:**
    *   Bit 0: Manual Control (Use pitch/roll to adjust radius/rate in flight)
    *   Bit 1: Face Direction of Travel
    *   Bit 2: Start at Center (Begin from the circle's center rather than flying to the perimeter)
    *   Bit 3: ROI at Center (Keep gimbal pointed at the circle center)