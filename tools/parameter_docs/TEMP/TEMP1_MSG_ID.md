---
layout: parameter
name: TEMP1_MSG_ID
display_name: Temperature DroneCAN Message ID
description: The specific DroneCAN device ID this temperature sensor instance listens for.
default_value: 0
range: 0 65535
units: 
group: TEMP
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_TemperatureSensor/AP_TemperatureSensor_DroneCAN.cpp#L36
---

# Temperature DroneCAN Message ID (TEMP1_MSG_ID)

## Description
`TEMP1_MSG_ID` identifies which specific piece of hardware on the DroneCAN bus is providing the temperature data for this instance.

This allows you to map multiple DroneCAN temperature sensors (e.g., from different ESCs or battery monitors) to specific slots in the autopilot's telemetry system.

## Tuning & Behavior
*   **Default:** 0 (Auto-detection).
*   **Usage:** Only set this if you have multiple sensors of the same type and need to force a specific one to Instance 1.
*   **Requirement:** Only used if [TEMP1_TYPE](TEMP1_TYPE.html) is set to **1 (DroneCAN)**.