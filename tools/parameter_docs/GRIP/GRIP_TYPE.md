---
layout: parameter
name: GRIP_TYPE
display_name: Gripper Type
description: Specifies the type of gripper hardware used.
default_value: 0
range: 0 2
units: 
group: GRIP
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Gripper/AP_Gripper.cpp
---

# Gripper Type (GRIP_TYPE)

## Description
Defines the mechanical interface for the gripper.
*   **0: None**
*   **1: Servo (Standard PWM servo mechanism)**
*   **2: EPM (Electro-Permanent Magnet)**
