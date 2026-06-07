---
layout: parameter
name: MAV1_EXTRA2
display_name: MAVLink Extra 2 Stream Rate (Telem 1)
description: Controls the streaming rate for the VFR_HUD message.
default_value: 1
range: 0 50
units: Hz
group: MAV
visual_asset_id: mav_stream_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/Rover/GCS_Mavlink.cpp#L564
---

# MAVLink Extra 2 Stream Rate (MAV1_EXTRA2)

## Description
`MAV1_EXTRA2` sets the update frequency for the "Dashboard" data. 

This stream group primarily contains the `VFR_HUD` message, which includes:
*   Airspeed.
*   Groundspeed.
*   Heading.
*   Throttle percentage.
*   Altitude.
*   Climb rate.

## Tuning & Behavior
*   **Default:** 1 Hz.
*   **Recommendation:** Set to **2 Hz** or **5 Hz** for a more responsive display of speed and altitude on your GCS dashboard. 
*   **Notes:** This message is the primary source of data for the "HUD" instrument in Mission Planner and QGroundControl.