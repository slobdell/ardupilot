---
layout: parameter
name: SCAN_SPEED_PIT
display_name: Antenna Tracker Scan Pitch Speed
description: The rotation speed (in deg/s) for the pitch axis while in SCAN mode.
default_value: 2
range: 0 100
units: deg/s
group: SCAN
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/AntennaTracker/Parameters.cpp#L538
---

# Antenna Tracker Scan Pitch Speed (SCAN_SPEED_PIT)

## Description
`SCAN_SPEED_PIT` defines the vertical sweep speed for the Antenna Tracker while searching for a signal.