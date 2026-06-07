---
layout: parameter
name: SIM_ARSPD_OFS
display_name: Simulated Airspeed Offset
description: The pressure offset (in Pascals) added to the simulated airspeed sensor.
default_value: 0
range: 0 100
units: Pa
group: SIM
visual_asset_id: sim_failure_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L1250
---

# Simulated Airspeed Offset (SIM_ARSPD_OFS)

## Description
`SIM_ARSPD_OFS` simulates a calibration error.

Airspeed sensors measure minute pressure differences. If the sensor isn't zeroed correctly before flight (e.g., if it was windy when you plugged in the battery), it will report speed even when sitting still. This parameter allows you to simulate that error and test if your pre-flight checks catch it.

## Tuning & Behavior
*   **Default Value:** 0 Pa.
*   **Testing:** Set to **100**. You should see the HUD report an airspeed of 5-10 m/s even while the drone is on the ground.