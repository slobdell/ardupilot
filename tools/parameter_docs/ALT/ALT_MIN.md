---
layout: parameter
name: ALT_MIN
display_name: Proximity lowest altitude
description: Minimum altitude below which proximity-based avoidance should be disabled.
default_value: 1.0
range: 0 10
units: m
group: ALT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Proximity/AP_Proximity.cpp
---

# Proximity lowest altitude (ALT_MIN)

## Description
Defines the minimum altitude above ground (AGL) required for proximity sensors and avoidance logic to become active. This prevents false triggers from the ground during takeoff and landing.

## Tuning & Behavior
*   **Default Value:** 1.0 m
*   **Range:** 0 to 10 m