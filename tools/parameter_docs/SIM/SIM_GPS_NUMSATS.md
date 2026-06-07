---
layout: parameter
name: SIM_GPS_NUMSATS
display_name: Simulation GPS Satellite Count
description: The number of satellites the simulated GPS reports as being in view.
default_value: 10
range: 0 30
units: 
group: SIM
visual_asset_id: sim_gps_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L109
---

# Simulation GPS Satellite Count (SIM_GPS_NUMSATS)

## Description
`SIM_GPS_NUMSATS` allows you to simulate "Signal Shading" or poor sky visibility.

ArduPilot's EKF requires a minimum number of satellites to maintain a high-quality position fix. By reducing this value in SITL, you can test how the drone behaves when it enters a "Degraded GPS" state.

*   **10 (Default):** Healthy fix.
*   **5:** Poor fix. EKF may report warnings.
*   **3:** Fix lost. Drone will switch to non-GPS modes.
