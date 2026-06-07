---
layout: parameter
name: SIM_GPS2_BYTELOS
display_name: Simulated GPS 2 Byte Loss
description: The percentage of bytes dropped from the GPS 2 serial stream.
default_value: 0
range: 0 100
units: '%'
group: SIM
visual_asset_id: sim_failure_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated GPS 2 Byte Loss (SIM_GPS2_BYTELOS)

## Description
`SIM_GPS2_BYTELOS` degrades the connection to the secondary GPS.

By dropping random bytes, you can simulate a loose cable or electrical noise on the UART line. This tests the GPS driver's ability to re-sync and the EKF's ability to handle packet loss.

## Tuning & Behavior
*   **Default Value:** 0%.