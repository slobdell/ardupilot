---
layout: parameter
name: SIM_ARSPD_FAILP
display_name: Simulated Airspeed Failure Pressure
description: The pressure (in Pascals) reported by the airspeed sensor when it fails.
default_value: 0
range: 0 1000
units: Pa
group: SIM
visual_asset_id: sim_failure_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated Airspeed Failure Pressure (SIM_ARSPD_FAILP)

## Description
`SIM_ARSPD_FAILP` allows you to choose what "Broken" looks like for your Pitot tube.

If `SIM_ARSPD_FAIL` is active, the sensor will freeze at this pressure.
*   **0 Pa:** Simulates a clogged tube (Zero airspeed). Useful for testing stall warnings.
*   **High Value:** Simulates a blocked static port (High airspeed).

## Tuning & Behavior
*   **Default Value:** 0 Pa.