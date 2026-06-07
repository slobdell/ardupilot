---
layout: parameter
name: MAV1_EXTRA1
display_name: MAVLink Extra 1 Stream Rate (Telem 1)
description: Controls the streaming rate for Attitude and PID tuning messages.
default_value: 1
range: 0 50
units: Hz
group: MAV
visual_asset_id: mav_stream_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/Rover/GCS_Mavlink.cpp#L554
---

# MAVLink Extra 1 Stream Rate (MAV1_EXTRA1)

## Description
`MAV1_EXTRA1` sets the update frequency for orientation and tuning data. 

This stream group includes:
*   `ATTITUDE` (Roll, Pitch, Yaw).
*   `SIMSTATE` (SITL only).
*   `AHRS2` (Secondary AHRS state).
*   `PID_TUNING` (Live data for GCS tuning graphs).

## Tuning & Behavior
*   **Default:** 1 Hz.
*   **Smooth HUD:** If you want a smooth artificial horizon on your GCS or OSD, set this to **4 Hz** or **10 Hz**.
*   **PID Tuning:** Set to **20 Hz** or **50 Hz** temporarily when using the GCS PID graphs to capture high-frequency oscillations.
*   **Bandwidth:** Higher rates consume more bandwidth. On a 57.6k SiK radio, avoid setting this above 10 Hz if other streams are active.