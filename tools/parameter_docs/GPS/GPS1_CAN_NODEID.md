---
layout: parameter
name: GPS1_CAN_NODEID
display_name: Detected CAN Node ID for GPS (GPS 1)
description: The detected DroneCAN Node ID for the primary GPS.
default_value: 0
range: 0 127
units: 
group: GPS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_GPS/AP_GPS_Params.cpp#L107
---

# Detected CAN Node ID for GPS (GPS1_CAN_NODEID)

## Description
`GPS1_CAN_NODEID` displays the DroneCAN (UAVCAN) Node ID that the autopilot has assigned to or detected from the primary GPS unit. This is a **Read-Only** parameter used for diagnostics.

*   **Role:** Identifies the specific hardware device on the CAN bus.
*   **Usage:** If you need to force the autopilot to use a specific GPS node, set [GPS1_CAN_OVRIDE](GPS1_CAN_OVRIDE.html) instead.

## The Engineer's View
*   **Storage:** `AP_GPS::Params::node_id` (Integer).
*   **Update Logic:** Updated by the `AP_GPS_DroneCAN` driver when a matching device is found and successfully configured.
*   **Persistence:** The value is saved to storage but overwritten on the next boot if detection changes.

## Tuning & Behavior
*   **Default:** 0 (No device detected yet).
*   **Normal Range:** 0-125 (Standard DroneCAN Node IDs).
*   **Dependency:** Requires `GPS1_TYPE` = 9 (DroneCAN).