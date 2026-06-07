---
layout: parameter
name: GRIP_ENABLE
display_name: Gripper Enable/Disable
description: Enables or disables the gripper (cargo release) module.
default_value: 0
range: 0 1
units: 
group: GRIP
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Gripper/AP_Gripper.cpp
---

# Gripper Enable/Disable (GRIP_ENABLE)

## Description
Master switch for the onboard gripper system, used for delivering or picking up cargo.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled)
*   **Requires reboot to make other GRIP_ parameters visible.**
