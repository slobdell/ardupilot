---
layout: parameter
name: MAV1_ADSB
display_name: MAVLink ADS-B Stream Rate (Telem 1)
description: Controls the MAVLink streaming rate for nearby aircraft information (ADS-B).
default_value: 5
range: 0 50
units: Hz
group: MAV
visual_asset_id: mav_stream_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/Rover/GCS_Mavlink.cpp#L594
---

# MAVLink ADS-B Stream Rate (MAV1_ADSB)

## Description
`MAV1_ADSB` sets the update frequency for traffic information on your GCS map. 

If your drone is equipped with an ADS-B receiver (like the Ping1090), it detects nearby full-sized aircraft. This parameter determines how often those plane positions are sent to your Ground Control Station.

## Tuning & Behavior
*   **Default:** 5 Hz (Note: Rover defaults to 0).
*   **Safety:** **5 Hz** is a good value to ensure you see approaching aircraft with minimal lag on your map.
*   **Bandwidth:** This stream only sends data when aircraft are actually detected. It consumes very little bandwidth when the sky is clear.