---
layout: parameter
name: SIM_GPS2_NOISE
display_name: Simulated GPS 2 Noise
description: The magnitude of random noise (in meters) added to the GPS 2 position measurements.
default_value: 0
range: 0 10
units: m
group: SIM
visual_asset_id: sim_noise_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated GPS 2 Noise (SIM_GPS2_NOISE)

## Description
`SIM_GPS2_NOISE` adds jitter to the secondary GPS.

Use this to test GPS Blending (`GPS_AUTO_SWITCH` = 2). You can make GPS 2 noisier than GPS 1 and verify that the autopilot correctly weights GPS 1 higher.

## Tuning & Behavior
*   **Default Value:** 0.