---
layout: parameter
name: FLOW_ORIENT_YAW
display_name: Flow sensor yaw alignment
description: Specifies the number of centi-degrees that the flow sensor is yawed relative to the vehicle. A sensor with its X-axis pointing to the right of the vehicle X axis has a positive yaw angle.
default_value: 0
range: -17999 +18000
units: cdeg
group: FLOW
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_OpticalFlow/AP_OpticalFlow.cpp
---

# Flow sensor yaw alignment (FLOW_ORIENT_YAW)

## Description
Yaw alignment of the flow sensor relative to the vehicle.

## Tuning & Behavior
*   **Default Value:** 0 cdeg
*   **Range:** -17999 18000