---
layout: parameter
name: MAV1_POSITION
display_name: MAVLink Position Stream Rate (Telem 1)
description: Controls the streaming rate for GPS and local position messages.
default_value: 1
range: 0 50
units: Hz
group: MAV
visual_asset_id: mav_stream_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/Rover/GCS_Mavlink.cpp#L544
---

# MAVLink Position Stream Rate (MAV1_POSITION)

## Description
`MAV1_POSITION` sets the update frequency for the vehicle's location data. 

This stream group includes:
*   `GLOBAL_POSITION_INT` (Latitude, Longitude, Altitude, Velocity).
*   `LOCAL_POSITION_NED` (Position relative to the home location).

## Tuning & Behavior
*   **Default:** 1 Hz.
*   **Map Smoothness:** If your drone "jumps" on the GCS map or in the HUD, increase this to **2 Hz** or **5 Hz**.
*   **Bandwidth:** This is one of the most important streams for basic navigation. Ensure it has a higher priority than "Extra" data groups if bandwidth is limited.