---
layout: parameter
name: SIM_GPS_POS
display_name: Simulation GPS Position Offset
description: Sets the physical distance of the simulated GPS antenna from the vehicle's center of gravity.
default_value: 0
range: -5 5
units: m
group: SIM
visual_asset_id: imu_pos_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L118
---

# Simulation GPS Position Offset (SIM_GPS_POS)

## Description
`SIM_GPS_POS` defines the mounting location of the virtual GPS antenna.

See [GPS_POS](../GPS/GPS_POS.html) for details on why antenna offsets are critical for flight stability.