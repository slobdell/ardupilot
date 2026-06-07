---
layout: parameter
name: MAV1_PARAMS
display_name: MAVLink Parameter Stream Rate
description: The frequency (in Hz) at which the flight controller sends parameter values over MAVLink.
default_value: 10
range: 0 50
units: Hz
group: MAV
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduCopter/GCS_Mavlink.cpp
---

# MAVLink Parameter Stream Rate (MAV1_PARAMS)

## Description
`MAV1_PARAMS` defines how fast ArduPilot "shouts" its settings to your Ground Control Station (GCS).

When you open the parameter list in Mission Planner or QGroundControl, this rate determines how quickly the data fills up your screen. If the rate is too low, the GCS will feel sluggish. If it is too high, it might consume too much bandwidth on a slow telemetry radio link.

## Tuning & Behavior
*   **Default:** 10 Hz.
*   **Recommendation:** Leave at **10** for most setups. If you are using a high-speed link (WiFi or Ethernet), you can increase this to **50** for instant parameter refreshes.
*   **Context:** This is the rate for `PARAM_VALUE` messages.