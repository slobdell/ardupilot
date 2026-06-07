---
layout: parameter
name: PRX1_RECV_ID
display_name: Proximity MAVLink System ID
description: The MAVLink System ID to listen to for proximity data when using a MAVLink-based sensor.
default_value: 0
range: 0 255
units: 
group: PRX
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Proximity/AP_Proximity_Params.cpp#L125
---

# Proximity MAVLink System ID (PRX1_RECV_ID)

## Description
`PRX1_RECV_ID` specifies the source of the proximity data when using a MAVLink-based sensor (like an OpenMV or a specialized companion computer script). 

It tells the autopilot: "Only listen to `DISTANCE_SENSOR` messages from this specific MAVLink system ID."

*   **0 (Default):** Listen to all MAVLink proximity sources.
*   **1-255:** Listen only to this specific System ID.