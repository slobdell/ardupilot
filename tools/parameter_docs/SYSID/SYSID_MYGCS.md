---
layout: parameter
name: SYSID_MYGCS
display_name: MAVLink GCS System ID
description: The specific MAVLink ID of the ground control station that is allowed to control this vehicle.
default_value: 255
range: 1 255
units: 
group: SYSID
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduCopter/Parameters.cpp
---

# MAVLink GCS System ID (SYSID_MYGCS)

## Description
`SYSID_MYGCS` sets the "Authorized" address for your ground control station (GCS).

In a MAVLink network, every device has a System ID. Most GCS software (Mission Planner, QGC) uses **255** as its default ID. This parameter tells the autopilot: "Only listen to commands from a GCS with this specific ID."

## Tuning & Behavior
*   **Default:** 255.
*   **Usage:** For most users, leave at **255**. Only change this if you are using a custom GCS or are operating in a multi-pilot environment where you want to lock your drone to a specific laptop/tablet to prevent accidental interference.
*   **Safety:** If you change this value and your GCS ID doesn't match, you may lose the ability to send commands to the drone via telemetry.