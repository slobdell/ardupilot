---
layout: parameter
name: EK3_BCN_M_NSE
display_name: EKF3 Beacon Measurement Noise
description: The expected noise (in meters) in range measurements from non-GPS beacons (e.g., Pozyx).
default_value: 1.0
range: 0.1 10.0
units: m
group: EK3
visual_asset_id: beacon_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_NavEKF3/AP_NavEKF3.cpp#L100
---

# EKF3 Beacon Measurement Noise (EK3_BCN_M_NSE)

## Description
`EK3_BCN_M_NSE` tells the EKF how much to "Trust" your indoor positioning beacons (like Pozyx or Marvelmind).

If your beacons have a lot of multi-path interference (echoes off walls), you should increase this value to prevent the drone from twitching. If they are very precise, you can decrease it to get a tighter position hold.

## Tuning & Behavior
*   **Default Value:** 1.0 m.
*   **High Precision:** Set to **0.5** if your beacon system consistently reports accuracy better than 10cm.
*   **Noisy Environment:** Set to **2.0** if you see the drone jumping around in tight indoor spaces.