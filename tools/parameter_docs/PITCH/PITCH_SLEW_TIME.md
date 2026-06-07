---
layout: parameter
name: PITCH_SLEW_TIME
display_name: Antenna Tracker Pitch Slew Time
description: The minimum time (in seconds) for the tracker to complete a full 180-degree pitch rotation.
default_value: 2
range: 0 20
units: s
group: PITCH
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/AntennaTracker/Parameters.cpp#L51
---

# Antenna Tracker Pitch Slew Time (PITCH_SLEW_TIME)

## Description
`PITCH_SLEW_TIME` acts as a speed governor for the Antenna Tracker's tilt axis.