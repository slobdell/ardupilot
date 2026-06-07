---
layout: parameter
name: PITCH_TRIM
display_name: Antenna Tracker Pitch Trim
description: Manual pitch offset (in degrees) to correct for mechanical misalignment or sensor drift on the tracker.
default_value: 0
range: -10 10
units: deg
group: PITCH
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/AntennaTracker/Parameters.cpp#L157
---

# Antenna Tracker Pitch Trim (PITCH_TRIM)

## Description
`PITCH_TRIM` allows you to tilt the Antenna Tracker's beam up or down manually.

This is useful if your tracker mount is not perfectly level, or if there is a consistent error in the altitude reported by the drone or the tracker's own sensors. By adding a few degrees of trim, you can center the antenna's signal beam exactly on the drone.

## Tuning & Behavior
*   **Default:** 0.
*   **Usage:** If you find the signal is strongest when you manually tilt the antenna slightly, enter that offset here so the software can handle it automatically.