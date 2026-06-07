---
layout: parameter
name: DDS_ENABLE
display_name: DDS enable
description: Enables the Data Distribution Service (DDS) / ROS2 integration subsystem.
default_value: 1
range: 0 1
units: 
group: DDS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_DDS/AP_DDS_Client.cpp
---

# DDS enable (DDS_ENABLE)

## Description
Master switch for the DDS (Data Distribution Service) client, which enables high-speed, native communication with ROS2 (Robot Operating System 2) environments.

## Tuning & Behavior
*   **Default Value:** 1 (Enabled if compiled in)
*   **Requires reboot to take effect.**