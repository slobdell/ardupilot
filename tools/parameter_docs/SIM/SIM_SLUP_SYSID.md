---
layout: parameter
name: SIM_SLUP_SYSID
display_name: Slung Payload MAVLink System ID
description: The MAVLink System ID of the simulated slung payload (for position reporting).
default_value: 2
range: 0 255
units: 
group: SIM
visual_asset_id: networking_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SIM_SlungPayload.cpp#L64
---

# Slung Payload MAVLink System ID (SIM_SLUP_SYSID)

## Description
`SIM_SLUP_SYSID` enables the slung payload to report its own position to the GCS.

When enabled, the simulator spawns a second MAVLink "Vehicle" at the payload's location. This allows you to see the payload swinging on your GCS map or in a 3D visualizer (like Mission Planner's HUD).

## Tuning & Behavior
*   **Default Value:** 2.
*   **Note:** The payload broadcasts heartbeats as a **MAV_TYPE_AIRSHIP** with component ID **MAV_COMP_ID_USER11**.