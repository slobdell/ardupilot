---
layout: parameter
name: SIM_GPS_JAM
display_name: Simulation GPS Jamming
description: Simulates GPS jamming by forcing a total loss of signal.
default_value: 0
range: 0 1
units: 
group: SIM
visual_asset_id: sim_gps_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L125
---

# Simulation GPS Jamming (SIM_GPS_JAM)

## Description
`SIM_GPS_JAM` simulates the drone flying into an area with a GPS jammer.

*   **0: Normal.** GPS works as expected.
*   **1: Jammed.** The autopilot instantly loses GPS fix, as if the antenna were disconnected. Use this to verify that your drone's EKF correctly fails over to dead-reckoning or triggers an immediate "Land" failsafe.