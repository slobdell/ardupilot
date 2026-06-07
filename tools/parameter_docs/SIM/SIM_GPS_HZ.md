---
layout: parameter
name: SIM_GPS_HZ
display_name: Simulation GPS Update Rate
description: The frequency (in Hz) at which the simulated GPS provides position updates.
default_value: 5
range: 1 50
units: Hz
group: SIM
visual_asset_id: sim_gps_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L111
---

# Simulation GPS Update Rate (SIM_GPS_HZ)

## Description
`SIM_GPS_HZ` sets the "Refresh Rate" of the simulated GPS.

*   **5 (Default):** Standard for most consumer GPS modules.
*   **10:** High performance (u-blox M8N/M9N).
*   **50:** Industrial RTK systems.

## Tuning & Behavior
*   **Default Value:** 5 Hz.
*   **Testing:** Use this to verify that your `GPS_RATE_MS` and `EKF` settings can handle higher data rates without CPU overload.
