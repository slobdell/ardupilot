---
layout: parameter
name: SIM_ARSPD_SIGN
display_name: Simulated Airspeed Sign
description: Multiplier for the airspeed sensor reading (1 or -1).
default_value: 1
range: -1 1
units: 
group: SIM
visual_asset_id: sim_failure_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated Airspeed Sign (SIM_ARSPD_SIGN)

## Description
`SIM_ARSPD_SIGN` simulates a common plumbing error: swapping the Pitot and Static tubes.

If set to **-1**, the airspeed sensor will report negative pressure, which typically results in zero airspeed or an error message.

## Tuning & Behavior
*   **Default Value:** 1.