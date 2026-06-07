---
layout: parameter
name: AVD_W_ACTION
display_name: Collision Avoidance Behavior - Warn
description: Specifies aircraft behaviour when a collision may occur (Warn threat level).
default_value: 1
range: 0 1
units: 
group: AVD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Avoidance/AP_Avoidance.cpp
---

# Collision Avoidance Behavior - Warn (AVD_W_ACTION)

## Description
Defines the action taken when a potential collision is detected within the W_TIME horizon.

## Tuning & Behavior
*   **Default Value:** 1 (Report)
*   **Values:** 0:None, 1:Report
*   **Usually set to "Report" to provide situational awareness without taking automatic flight control actions.**