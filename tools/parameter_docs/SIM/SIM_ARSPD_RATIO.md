---
layout: parameter
name: SIM_ARSPD_RATIO
display_name: Simulated Airspeed Ratio
description: The pressure-to-airspeed ratio for the simulated sensor.
default_value: 2
range: 1 4
units: 
group: SIM
visual_asset_id: sim_failure_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L1250
---

# Simulated Airspeed Ratio (SIM_ARSPD_RATIO)

## Description
`SIM_ARSPD_RATIO` sets the sensitivity of the virtual pitot tube.

This corresponds to the `ARSPD_RATIO` parameter in the flight controller. If they don't match, your airspeed reading will be wrong.

## Tuning & Behavior
*   **Default Value:** 2.
*   **Testing:** Change this to **3** and see if `ARSPD_AUTOCAL` can figure it out.