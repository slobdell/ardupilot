---
layout: parameter
name: GRIP_REGRAB
display_name: EPM Gripper Regrab interval
description: Time in seconds that EPM gripper will regrab the cargo to ensure grip has not weakened.
default_value: 0
range: 0 255
units: s
group: GRIP
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Gripper/AP_Gripper.cpp
---

# EPM Gripper Regrab interval (GRIP_REGRAB)

## Description
For Electro-Permanent Magnets (EPM), defines how often the flight controller should send a "Grab" pulse to ensure the cargo remains securely attached, compensating for physical jostling.
*   **0 disables automatic regrabbing.**