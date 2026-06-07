---
layout: parameter
name: SIM_GPS_TYPE
display_name: Simulation GPS Type
description: Selects the hardware protocol and chip model being simulated for the first GPS instance.
default_value: 1
range: 0 26
units: 
group: SIM
visual_asset_id: sim_gps_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L103
---

# Simulation GPS Type (SIM_GPS_TYPE)

## Description
`SIM_GPS_TYPE` tells the simulator which "Language" to use when sending data to the autopilot. 

*   **1: u-blox (Standard).** The most common GPS type.
*   **5: NMEA.** Generic serial data.
*   **9: DroneCAN.** Simulates a CAN-bus GPS.
*   **14: MAVLink.**