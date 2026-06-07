---
layout: parameter
name: START_LATITUDE
display_name: Initial Tracker Latitude
description: The manual latitude coordinate for the antenna tracker's starting location.
default_value: 0
range: -90 90
units: deg
group: START
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/AntennaTracker/Parameters.cpp#L71
---

# Initial Tracker Latitude (START_LATITUDE)

## Description
`START_LATITUDE` (working with [START_LONGITUDE](START_LONGITUDE.html)) allows you to manually tell an **Antenna Tracker** where it is physically located.

This is primarily used for trackers that do not have their own internal GPS. By providing these coordinates, the tracker can calculate the correct pointing angle toward the drone based on the drone's GPS telemetry.

## Tuning & Behavior
*   **Default:** 0.
*   **Usage:** Enter the exact latitude of your ground station. If the tracker *does* have a GPS lock, this parameter is overridden by the real sensor data.