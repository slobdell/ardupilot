---
layout: parameter
name: FRAME_TYPE
display_name: Frame Type
description: Specifies the orientation of the motors within the frame class.
default_value: 1
range: 0 5
units: 
group: FRAME
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduCopter/Parameters.cpp
---

# Frame Type (FRAME_TYPE)

## Description
Defines the specific layout of the motors relative to the nose of the aircraft (e.g., Plus vs. X configuration).

## Tuning & Behavior
*   **Default Value:** 1 (X)
*   **Common Values:** 0:Plus, 1:X, 2:V, 3:H, 10:Y6B
*   **Requires reboot to take effect.**