---
layout: parameter
name: CRASH_ANGLE
display_name: Crash Angle
description: Maximum pitch or roll angle allowed before the crash detector is triggered (Rover).
default_value: 0
range: 0 90
units: deg
group: CRASH
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/Rover/Parameters.cpp
---

# Crash Angle (CRASH_ANGLE)

## Description
Defines the tip-over threshold for Rover vehicles. If the vehicle's roll or pitch angle exceeds this value, it will be considered crashed and the motors will be disabled.
*   **A value of 0 disables the tip-over check.**