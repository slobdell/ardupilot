---
layout: parameter
name: SIM_GPS_LOG_NUM
display_name: Simulated GPS Log Number
description: The log number (from DataFlash logs) to use for GPS replay.
default_value: 0
range: 0 100
units: 
group: SIM
visual_asset_id: sim_gps_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated GPS Log Number (SIM_GPS_LOG_NUM)

## Description
`SIM_GPS_LOG_NUM` allows you to replay a specific GPS track from a previous flight log.

If you have a DataFlash log (e.g., `00000012.BIN`) where the GPS glitched or behaved weirdly, you can feed that exact GPS data into the simulator to see if the EKF can handle it better with different settings.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled).
*   **Usage:** Set `SIM_GPS_TYPE` to **7 (File)** and set this parameter to the log index you want to replay.