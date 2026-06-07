---
layout: parameter
name: WP_NAVALT_MIN
display_name: Minimum navigation altitude
description: This is the altitude in meters above which for navigation can begin. This applies in auto takeoff and auto landing.
default_value: 0
range: 0 5
units: m
group: WP
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduCopter/Parameters.cpp
---

# Minimum navigation altitude (WP_NAVALT_MIN)

## Description
Minimum altitude for navigation to begin.

## Tuning & Behavior
*   **Default Value:** 0
*   **Range:** 0 5