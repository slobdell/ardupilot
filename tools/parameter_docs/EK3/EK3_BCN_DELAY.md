---
layout: parameter
name: EK3_BCN_DELAY
display_name: EKF3 Beacon Delay
description: The delay (in ms) of the optical flow or beacon data relative to the IMU.
default_value: 50
range: 0 500
units: ms
group: EK3
visual_asset_id: ekf_noise_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_NavEKF3/AP_NavEKF3.cpp#L100
---

# EKF3 Beacon Delay (EK3_BCN_DELAY)

## Description
`EK3_BCN_DELAY` compensates for the time it takes for a Range Beacon (like Pozyx) or Optical Flow sensor to process data and send it to the flight controller.

The EKF uses a "Time Horizon" to rewind history and fuse this delayed data with the correct IMU timestamp.

## Tuning & Behavior
*   **Default Value:** 50 ms.
*   **Recommendation:** Check your beacon system's datasheet. Incorrect delay causes "toilet bowling" (spiraling) when stopping or changing direction.