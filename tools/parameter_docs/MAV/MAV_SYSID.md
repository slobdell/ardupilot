---
layout: parameter
name: MAV_SYSID
display_name: Slung Payload MAVLink System ID
description: The specific MAVLink System ID assigned to the slung payload to distinguish it from the vehicle and other components.
default_value: 2
range: 1 255
units: 
group: MAV
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/SITL/SIM_SlungPayload.cpp#L71
---

# Slung Payload MAVLink System ID (MAV_SYSID)

## Description
`MAV_SYSID` is used when simulating or controlling a **Slung Payload** (a weight hanging from the drone via a cable).

In a MAVLink network, every independent object (the drone, the GCS, the payload) needs its own System ID. This parameter identifies the payload itself, allowing ground station software to track the payload's position and orientation separately from the drone's.

## Tuning & Behavior
*   **Default:** 2.
*   **Usage:** Only relevant for advanced missions involving autonomous slung load delivery or research. Most users can leave this at the default.