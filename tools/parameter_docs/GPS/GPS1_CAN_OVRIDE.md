---
layout: parameter
name: GPS1_CAN_OVRIDE
display_name: GPS DroneCAN Node ID Override (Sensor 1)
description: Manually locks the primary GPS to a specific DroneCAN Node ID.
default_value: 0
range: 0 127
units: 
group: GPS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_GPS/AP_GPS_Params.cpp#L113
---

# GPS DroneCAN Node ID Override (GPS1_CAN_OVRIDE)

## Description
`GPS1_CAN_OVRIDE` allows you to force ArduPilot to use a specific GPS unit as the "Primary" when you have multiple GPS units connected via DroneCAN (UAVCAN).

*   **0 (Default):** First-come, first-served. The autopilot uses the first DroneCAN GPS it detects on the bus.
*   **1-125:** Locks the primary GPS slot to the hardware with this specific Node ID.

## Tuning & Behavior
*   **Default:** 0.
*   **Usage:** Only set this if you have two identical DroneCAN GPS units and you want to ensure a specific physical one (e.g., the one with the best view of the sky) is always used as Instance 1.
*   **Reboot Required:** Yes.