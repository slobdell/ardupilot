---
layout: parameter
name: PRX_LOG_RAW
display_name: Proximity Raw Data Logging
description: Toggles high-frequency logging of raw, unfiltered proximity distances.
default_value: 0
range: 0 1
units: 
group: PRX
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Proximity/AP_Proximity.cpp#L61
---

# Proximity Raw Data Logging (PRX_LOG_RAW)

## Description
`PRX_LOG_RAW` is a developer and troubleshooting tool. 

When enabled, the autopilot records every individual measurement from the proximity sensor (e.g. all 360 degrees of data from a Lidar) into the internal DataFlash log. 

*   **0: Disabled (Default).** Only the processed "Boundary" data is logged.
*   **1: Enabled.** Logs the full raw data stream.

## Tuning & Behavior
*   **Warning:** This creates extremely large log files. 
*   **Usage:** Only enable this if you are debugging a sensor issue or verifying that your ignore sectors ([PRX1_IGN_ANG1](PRX1_IGN_ANG1.html)) are correctly configured.