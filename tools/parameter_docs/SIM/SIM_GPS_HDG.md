---
layout: parameter
name: SIM_GPS_HDG
display_name: Simulated GPS Heading Enable
description: Enables the output of simulated GPS heading messages (NMEA HDT or U-Blox RELPOSNED).
default_value: 0
range: 0 3
units: 
group: SIM
visual_asset_id: sim_gps_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L199
---

# Simulated GPS Heading Enable (SIM_GPS_HDG)

## Description
`SIM_GPS_HDG` allows the virtual GPS to report a "Moving Base" heading.

This is used for testing **GPS-for-Yaw** (Dual Antenna) setups in SITL. It tells the simulator to generate the relative position and heading messages that a real U-Blox or NMEA GPS would send when acting as a heading source.

## Tuning & Behavior
*   **0:** None.
*   **1:** NMEA HDT sentence.
*   **2:** U-Blox RELPOSNED.
*   **3:** NMEA THS sentence.