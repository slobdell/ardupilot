---
layout: parameter
name: DDS_DOMAIN_ID
display_name: DDS Domain ID (ROS2)
description: Sets the ROS_DOMAIN_ID for the onboard DDS client to communicate with ROS2 nodes.
default_value: 0
range: 0 232
units: 
group: DDS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_DDS/AP_DDS_Client.cpp#L134
---

# DDS Domain ID (DDS_DOMAIN_ID)

## Description
`DDS_DOMAIN_ID` is used for high-level robotics integration with **ROS2** (Robot Operating System).

In a ROS2 network, different groups of robots and computers can be isolated by using a "Domain ID." For the autopilot to talk to your companion computer (e.g. Jetson, Raspberry Pi) running ROS2 nodes, this parameter must match the `ROS_DOMAIN_ID` environment variable set on your computer.

## Tuning & Behavior
*   **Default:** 0.
*   **Usage:** Ensure this matches your ROS2 network configuration. If they don't match, the autopilot and the companion computer will not "see" each other.
*   **Reboot Required:** Yes.