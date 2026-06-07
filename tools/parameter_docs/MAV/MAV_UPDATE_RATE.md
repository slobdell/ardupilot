---
layout: parameter
name: MAV_UPDATE_RATE
display_name: Slung Payload Update Rate
description: The frequency (in Hz) at which the slung payload's state (Position, Attitude) is updated over MAVLink.
default_value: 1
range: 1 10
units: Hz
group: MAV
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/AntennaTracker/Parameters.cpp#L191
---

# Slung Payload Update Rate (MAV_UPDATE_RATE)

## Description
`MAV_UPDATE_RATE` defines how often the simulated or real slung payload sends its data to the flight controller or ground station.