---
layout: parameter
name: SIM_GPS_NOISE
display_name: Simulated GPS Noise
description: The magnitude of random noise (in meters) added to the primary simulated GPS position measurements.
default_value: 0
range: 0 10
units: m
group: SIM
visual_asset_id: sim_noise_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated GPS Noise (SIM_GPS_NOISE)

## Description
`SIM_GPS_NOISE` adds random position jitter to the virtual GPS.

Unlike `SIM_GPS_ACC` (which only *reports* accuracy), this parameter actually moves the reported latitude/longitude/altitude by a random amount in every frame. This is the primary tool for testing how much GPS "Fuzz" your EKF can handle before the drone starts to wander or failsafes.

## Tuning & Behavior
*   **Default Value:** 0 (Perfect GPS).
*   **Recommendation:** Set to **0.5 or 1.0** to simulate a realistic low-cost GPS in an open field. Set to **3.0+** to simulate urban canyon environments.