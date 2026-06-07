---
layout: parameter
name: MNT1_DEVID
display_name: Mount Device ID (Instance 1)
description: Unique hardware identifier for the gimbal controller.
default_value: 0
range: 
units: 
group: MNT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Mount/AP_Mount_Params.cpp#L167
---

# Mount Device ID (MNT1_DEVID)

## Description
`MNT1_DEVID` is a **Read-Only** diagnostic parameter that stores the unique hardware ID of the detected gimbal. It encodes the driver type, the communication bus (e.g. DroneCAN, I2C), and the bus address.

*   **Role:** Verifies that the autopilot has successfully connected to the external gimbal hardware.
*   **Usage:** If this is 0, the autopilot has failed to detect the gimbal specified in [MNT1_TYPE](MNT1_TYPE.html).

## Tuning & Behavior
*   **Default:** 0.
*   **Action:** No user adjustment is possible. This is used by the system to ensure it is talking to the correct device instance.