---
layout: parameter
name: SCAN_SPEED_YAW
display_name: Antenna Tracker Scan Yaw Speed
description: The rotation speed (in deg/s) for the yaw axis while in SCAN mode.
default_value: 2
range: 0 100
units: deg/s
group: SCAN
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/AntennaTracker/Parameters.cpp#L531
---

# Antenna Tracker Scan Yaw Speed (SCAN_SPEED_YAW)

## Description
`SCAN_SPEED_YAW` defines how fast the Antenna Tracker "looks around" when it loses its connection to the drone.

In **SCAN** mode, the tracker performs a pre-defined sweeping pattern to re-acquire the telemetry signal. This parameter sets the horizontal sweep speed. 

## Tuning & Behavior
*   **Default:** 2 deg/s.
*   **Recommendation:** Keep this relatively low. If the tracker moves too fast, it might sweep past the signal before the radio can achieve a "Link."