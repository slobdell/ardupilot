---
layout: parameter
name: GRIP_AUTOCLOSE
display_name: Gripper Autoclose time
description: Time in seconds that the gripper will automatically close after opening.
default_value: 0.0
range: 0.25 255
units: s
group: GRIP
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Gripper/AP_Gripper.cpp
---

# Gripper Autoclose time (GRIP_AUTOCLOSE)

## Description
Automates the closure of the gripper after a successful release. This is often used to return a mechanical claw to its idle/stowed position.
*   **0 disables automatic closure.**