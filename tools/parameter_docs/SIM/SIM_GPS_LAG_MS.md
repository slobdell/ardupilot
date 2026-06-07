---
layout: parameter
name: SIM_GPS_LAG_MS
display_name: Simulated GPS Lag
description: The processing delay (in milliseconds) for the primary simulated GPS.
default_value: 120
range: 0 500
units: ms
group: SIM
visual_asset_id: sim_lag_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated GPS Lag (SIM_GPS_LAG_MS)

## Description
`SIM_GPS_LAG_MS` simulates the time it takes for a GPS module to calculate your position and send it over the wire.

Real GPS units always have a delay (latency). This parameter is critical for EKF tuning; the EKF needs to know how "Old" the GPS data is so it can align it with the high-speed IMU data.

## Tuning & Behavior
*   **Default Value:** 120 ms.
*   **Recommendation:** Set to match your hardware (e.g., U-Blox M8N is typically around **200ms**, M9N is closer to **80-120ms**).