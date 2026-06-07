---
layout: parameter
name: SIM_GPS_DISABLE
display_name: Simulation GPS Disable
description: Disables the simulated GPS to test Non-GPS flight modes.
default_value: 0
range: 0 1
units: 
group: SIM
visual_asset_id: sim_gps_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L110
---

# Simulation GPS Disable (SIM_GPS_DISABLE)

## Description
`SIM_GPS_DISABLE` kills the GPS signal.

*   **0:** GPS Enabled.
*   **1:** GPS Disabled (No Fix).

## Tuning & Behavior
*   **Default Value:** 0.
*   **Testing:** Use to test Optical Flow, T265 Realsense, or just plain AltHold/Stabilize flight without GPS assistance.
