---
layout: parameter
name: SYSID_THISMAV
display_name: MAVLink System ID
description: Unique ID for the vehicle on the MAVLink network.
default_value: 1
range: 1 255
units: 
group: SYSID
visual_asset_id: mavlink_network_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/GCS_MAVLink/GCS_Common.cpp
---

# MAVLink System ID (SYSID_THISMAV)

## Description
`SYSID_THISMAV` sets the "Address" of your drone on the MAVLink network. 

If you are flying multiple drones at the same time with the same Ground Control Station (GCS), each drone **must** have a unique `SYSID_THISMAV`. If two drones have the same ID, the GCS will get confused and may display erratic data or fail to send commands correctly.

*   **Default:** 1.
*   **Recommended Range:** 1 to 255.

## Tuning & Behavior
*   **Default:** 1.
*   **Action:** Change this to any unique number (e.g., Drone 1 = 1, Drone 2 = 2) when performing multi-vehicle operations.
*   **Compatibility:** Most MAVLink systems expect the GCS to be ID 255. Avoid setting your drone to 255.