---
layout: parameter
name: PLND_LAG
display_name: Precision Landing Sensor Lag
description: The time delay (in seconds) between when the sensor captures the target and when the autopilot receives the data.
default_value: 0.02
range: 0.02 0.250
units: s
group: PLND
visual_asset_id: sim_lag_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PrecLand/AC_PrecLand.cpp#L97
---

# Precision Landing Sensor Lag (PLND_LAG)

## Description
`PLND_LAG` compensates for the processing time of your landing camera or sensor.

Computer vision takes time. By the time a Raspberry Pi or OpenMV cam tells the flight controller "The target is at X,Y," the drone has already moved several centimeters. This parameter allows the EKF to "Rewind" its internal state to match the moment the photo was actually taken, resulting in much smoother and more accurate centering.

*   **Default Value:** 0.02 seconds (20ms).
*   **Too High:** The drone will "overshoot" its corrections.
*   **Too Low:** The drone will feel sluggish and take longer to center.

## Tuning & Behavior
*   **Default Value:** 0.02s.
*   **Recommendation:**
    *   **IR-Lock:** 0.02s - 0.04s.
    *   **Companion Computer (OpenCV):** 0.05s - 0.10s.