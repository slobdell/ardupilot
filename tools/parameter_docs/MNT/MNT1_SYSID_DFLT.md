---
layout: parameter
name: MNT1_SYSID_DFLT
display_name: Mount Target System ID
description: Sets the default MAVLink System ID of the gimbal being controlled.
default_value: 0
range: 0 255
units: 
group: MNT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Mount/AP_Mount_Params.cpp#L161
---

# Mount Target System ID (MNT1_SYSID_DFLT)

## Description
`MNT1_SYSID_DFLT` specifies the "Network Address" of the gimbal. 

In a MAVLink network (where multiple components like the autopilot, gimbal, and camera communicate), this ID allows the autopilot to send tilt/pan commands specifically to the correct gimbal controller. 

*   **0 (Default):** The autopilot will attempt to automatically find the first gimbal on the network.
*   **1-255:** Manually locks the autopilot to a specific MAVLink system ID.

## Tuning & Behavior
*   **Default:** 0.
*   **Usage:** Only set this if you have multiple gimbals (e.g. forward and downward) and the autopilot is consistently trying to control the wrong one.
*   **Reboot Required:** Yes.