---
layout: parameter
name: YAW_RANGE
display_name: Antenna Tracker Yaw Range
description: The total angular range of motion (in degrees) for the yaw axis.
default_value: 360
range: 0 360
units: deg
group: YAW
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/AntennaTracker/Parameters.cpp#L166
---

# Antenna Tracker Yaw Range (YAW_RANGE)

## Description
`YAW_RANGE` defines the mechanical limits of the tracker's pan axis.

Antenna trackers often have slip-rings (allowing continuous 360 rotation) or cable limits. This parameter tells the software how far it can turn before it needs to stop or "unwind."

*   **360 (Default):** Full rotation allowed (assuming slip ring).
*   **180:** Limited rotation (e.g. +/- 90 degrees).

## Tuning & Behavior
*   **Safety:** If you do not have a slip ring, setting this correctly is vital to prevent tearing your antenna cables.