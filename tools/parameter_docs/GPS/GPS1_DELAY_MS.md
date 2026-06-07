---
layout: parameter
name: GPS1_DELAY_MS
display_name: GPS Processing Delay (Sensor 1)
description: Manually specifies the latency (in milliseconds) of the GPS position data.
default_value: 0
range: 0 250
units: ms
group: GPS
visual_asset_id: sim_lag_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_GPS/AP_GPS_Params.cpp#L81
---

# GPS Processing Delay (GPS1_DELAY_MS)

## Description
`GPS1_DELAY_MS` tells the autopilot how "Old" the GPS data is when it arrives at the flight controller.

GPS modules take time to calculate position. By the time the autopilot receives the signal, the drone has already moved slightly. For accurate navigation, the EKF (Extended Kalman Filter) needs to know this delay so it can correctly align the GPS data with the high-speed inertial data (IMU).

*   **0 (Default):** Use the driver's hard-coded default for the detected GPS type (e.g. 200ms for u-blox M8N).
*   **1-250:** Manual override in milliseconds.

## Tuning & Behavior
*   **Default:** 0.
*   **Recommendation:** Leave at **0** for most users. Only adjust this if you are using an exotic or custom GPS module and you see "Horizontal Position Drift" during aggressive maneuvering.