---
layout: parameter
name: DOMAIN_ID
display_name: DDS Domain ID
description: Specifies the ROS_DOMAIN_ID for the Data Distribution Service (DDS) subsystem.
default_value: 0
range: 0 232
units: 
group: DOMAIN
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_DDS/AP_DDS_Client.cpp
---

# DDS Domain ID (DOMAIN_ID)

## Description
Matches the ArduPilot DDS client to a specific ROS2 logical network (domain). Only nodes with the same Domain ID can communicate with each other.

## Tuning & Behavior
*   **Default Value:** 0
*   **Range:** 0 to 232
*   **Must match the ROS_DOMAIN_ID environment variable on your companion computer.**