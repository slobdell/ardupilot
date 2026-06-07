---
layout: parameter
name: FRAME_CLASS
display_name: Frame Class
description: Specifies the major class of the vehicle frame.
default_value: 0
range: 0 15
units: 
group: FRAME
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduCopter/Parameters.cpp
---

# Frame Class (FRAME_CLASS)

## Description
Defines the overall architecture of the vehicle (e.g., Quad, Hexa, Octa, Heli, etc.). This setting determines how many motors are used and how they are fundamentally controlled.

## Tuning & Behavior
*   **Default Value:** 0 (Undefined)
*   **Common Values (Copter):** 1:Quad, 2:Hexa, 3:Octa, 6:Heli
*   **Common Values (Rover):** 1:Ground Vehicle, 2:Boat
*   **Requires reboot to take effect.**