---
layout: parameter
name: SIM_GPS2_DRFTALT
display_name: Simulated GPS 2 Altitude Drift
description: The rate of vertical drift (in m/s) applied to the second GPS altitude.
default_value: 0
range: 0 5
units: m/s
group: SIM
visual_asset_id: sim_gps_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated GPS 2 Altitude Drift (SIM_GPS2_DRFTALT)

## Description
`SIM_GPS2_DRFTALT` makes the secondary GPS "Float" vertically.

GPS altitude is notoriously unreliable. This parameter adds a slow, continuous change to the reported height, allowing you to verify that the EKF (which usually trusts the Barometer for height) ignores the bad GPS altitude data.

## Tuning & Behavior
*   **Default Value:** 0.