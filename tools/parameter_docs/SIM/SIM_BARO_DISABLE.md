---
layout: parameter
name: SIM_BARO_DISABLE
display_name: Disable Simulated Barometer
description: Disables the first simulated barometer.
default_value: 0
range: 0 1
units: 
group: SIM
visual_asset_id: sim_failure_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L198
---

# Disable Simulated Barometer (SIM_BARO_DISABLE)

## Description
`SIM_BARO_DISABLE` kills the primary barometer signal. 

Use this to test your drone's ability to maintain altitude using ONLY the IMU (which will drift) or a secondary source (like a Rangefinder).

## Tuning & Behavior
*   **Default Value:** 0
*   **Recommendation:** Use in flight to verify your "Secondary Altitude Source" logic.