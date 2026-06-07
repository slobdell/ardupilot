---
layout: parameter
name: SIM_ARSPD_RND
display_name: Simulated Airspeed Noise
description: The amount of noise (in m/s) added to the simulated airspeed sensor.
default_value: 2
range: 0 20
units: m/s
group: SIM
visual_asset_id: sim_noise_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L1250
---

# Simulated Airspeed Noise (SIM_ARSPD_RND)

## Description
`SIM_ARSPD_RND` injects noise into the virtual pitot tube.

Airspeed sensors are notoriously noisy due to wind gusts and turbulence. This parameter helps you tune your TECS (Total Energy Control System) to ignore that noise.

*   **0:** Perfect, clean airspeed data.
*   **2 (Default):** Realistic turbulence.

## Tuning & Behavior
*   **Default Value:** 2.0 m/s.
*   **Recommendation:** Keep at **2.0** to ensure your PID tuning is robust enough for real-world flight.