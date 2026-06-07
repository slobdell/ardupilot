---
layout: parameter
name: MAV1_EXTRA3
display_name: MAVLink Extra 3 Stream Rate (Telem 1)
description: Controls the streaming rate for System Status, Battery, and sensor health messages.
default_value: 1
range: 0 50
units: Hz
group: MAV
visual_asset_id: mav_stream_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/Rover/GCS_Mavlink.cpp#L574
---

# MAVLink Extra 3 Stream Rate (MAV1_EXTRA3)

## Description
`MAV1_EXTRA3` sets the update frequency for a variety of "Housekeeping" and secondary sensor messages. 

This stream group includes:
*   `SYSTEM_TIME` and `AHRS` status.
*   `BATTERY_STATUS` (Voltage, Current, Capacity).
*   `WIND` (Direction and Speed).
*   `VIBRATION` (Live clipping and vibe levels).
*   `RPM` and `ESC_TELEMETRY`.
*   `RANGEFINDER` and `OPTICAL_FLOW`.

## Tuning & Behavior
*   **Default:** 1 Hz.
*   **Recommendation:** **1 Hz** or **2 Hz** is usually sufficient for these values, as they do not change rapidly. 
*   **Bandwidth:** This group is quite large (many different messages). Increasing the rate can significantly impact bandwidth on low-speed telemetry links.