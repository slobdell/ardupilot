---
layout: parameter
name: AHRS_CUSTOM_YAW
display_name: Board orientation yaw offset
description: Autopilot mounting position yaw offset. Positive values = yaw right, negative values = yaw left. This parameter is only used when AHRS_ORIENTATION is set to CUSTOM (100).
default_value: 0
range: -180 180
units: deg
group: AHRS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_AHRS/AP_AHRS.cpp
---

# Board orientation yaw offset (AHRS_CUSTOM_YAW)

## Description
Fine-tuning for the autopilot mounting angle in the yaw axis.

## Tuning & Behavior
*   **Default Value:** 0 deg
*   **Range:** -180 to 180 deg
*   **Only active if AHRS_ORIENTATION is set to 100 (Custom).**