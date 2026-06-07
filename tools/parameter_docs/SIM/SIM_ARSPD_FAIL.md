---
layout: parameter
name: SIM_ARSPD_FAIL
display_name: Simulated Airspeed Failure Value
description: The value (in m/s) the airspeed sensor reports when it fails.
default_value: 0
range: 0 100
units: m/s
group: SIM
visual_asset_id: sim_failure_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L1254
---

# Simulated Airspeed Failure Value (SIM_ARSPD_FAIL)

## Description
`SIM_ARSPD_FAIL` allows you to simulate a "Stuck Sensor" or a "Clogged Pitot Tube."

By setting this to a static value (like 0 or 100), you can verify that the autopilot detects the failure and switches to "Synthetic Airspeed" (estimating speed from throttle and pitch) or triggers a failsafe.

## The Engineer's View
If this value is non-zero (or if you toggle the failure flag in the SITL backend), the sensor driver will lock its output to this value.
*   **0 m/s:** Simulates a pitot tube cover left on.
*   **High Value:** Simulates a sensor blowing out or water ingress.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled/Normal Operation).
*   **Testing:** Set to **0** while flying to simulate a blockage. Watch if the EKF declares the sensor "Unhealthy."