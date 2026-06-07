---
layout: parameter
name: DDS_TIMEOUT_MS
display_name: DDS Connection Timeout
description: The maximum time (in milliseconds) to wait for a successful DDS connection before reporting a failure.
default_value: 1000
range: 100 5000
units: ms
group: DDS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_DDS/AP_DDS_Client.cpp#L145
---

# DDS Connection Timeout (DDS_TIMEOUT_MS)

## Description
`DDS_TIMEOUT_MS` defines how patient the autopilot is when trying to establish a link with the ROS2 network.