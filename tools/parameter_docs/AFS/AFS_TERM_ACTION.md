---
layout: parameter
name: AFS_TERM_ACTION
display_name: Terminate action
description: This can be used to force an action on flight termination. Normally this is handled by an external failsafe board, but you can setup ArduPilot to handle it here.
default_value: 0
range: 
units: 
group: AFS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_AdvancedFailsafe/AP_AdvancedFailsafe.cpp
---

# Terminate action (AFS_TERM_ACTION)

## Description
Specific vehicle behavior to execute when termination is triggered.

## Tuning & Behavior
*   **Default Value:** 0
*   **Common values include crashing or immediate landing.**