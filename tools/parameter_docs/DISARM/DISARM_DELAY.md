---
layout: parameter
name: DISARM_DELAY
display_name: Disarm delay
description: Delay before automatic disarm in seconds. A value of zero disables auto disarm.
default_value: 10
range: 0 127
units: s
group: DISARM
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduCopter/Parameters.cpp
---

# Disarm delay (DISARM_DELAY)

## Description
Defines the period of inactivity (typically at zero throttle and landed) after which the flight controller will automatically disarm the motors for safety.

## Tuning & Behavior
*   **Default Value:** 10 s (Typical)
*   **Range:** 0 to 127 s
*   **Setting to 0 disables the auto-disarm feature.**