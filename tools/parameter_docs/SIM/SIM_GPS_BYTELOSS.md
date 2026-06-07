---
layout: parameter
name: SIM_GPS_BYTELOSS
display_name: Simulation GPS Byte Loss
description: The percentage of serial bytes randomly dropped from the simulated GPS data stream.
default_value: 0
range: 0 100
units: '%'
group: SIM
visual_asset_id: sim_gps_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L108
---

# Simulation GPS Byte Loss (SIM_GPS_BYTELOSS)

## Description
`SIM_GPS_BYTELOSS` simulates a flaky or noisy serial cable.

By randomly dropping a percentage of the data packets coming from the GPS, you can test how ArduPilot handles "Checksum Errors" and "Intermittent GPS" failures.

## Tuning & Behavior
*   **Default Value:** 0.
*   **Testing:** Set to **10**. You should see "GPS Glitch" or "GPS 1: Checksum error" messages in your GCS.