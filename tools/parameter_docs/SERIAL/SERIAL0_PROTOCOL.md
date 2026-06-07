---
layout: parameter
name: SERIAL0_PROTOCOL
display_name: Console/USB Protocol
description: Selects the communication protocol for the SERIAL0 (primary console/USB) port.
default_value: 2
range: -1 42
units: 
group: SERIAL
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_SerialManager/AP_SerialManager.cpp#L137
---

# Console/USB Protocol (SERIAL0_PROTOCOL)

## Description
`SERIAL0_PROTOCOL` tells the autopilot what "Language" to speak on the primary USB/Console port.

*   **2 (Default):** MAVLink 2. Standard protocol for Ground Control Stations (Mission Planner, QGC).
*   **-1:** None / Disabled.
*   **1:** MAVLink 1.

## Tuning & Behavior
*   **Recommendation:** Leave at **2** for all normal operations.
*   **Caution:** If you change this to a non-MAVLink protocol, you may lose the ability to connect to the flight controller via USB to change parameters. You would then need to connect via a different telemetry port to fix the setting.