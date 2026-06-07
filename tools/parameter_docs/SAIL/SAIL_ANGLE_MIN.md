---
layout: parameter
name: SAIL_ANGLE_MIN
display_name: Sail Minimum Angle
description: The angle between the vehicle centerline and the boom when the sail is fully sheeted in.
default_value: 0
range: 0 90
units: deg
group: SAIL
visual_asset_id: sailboat_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/Rover/sailboat.cpp#L40
---

# Sail Minimum Angle (SAIL_ANGLE_MIN)

## Description
`SAIL_ANGLE_MIN` defines the "Fully In" position of the sailboat's rig. 

It represents the angle of the boom relative to the boat's centerline when the mainsheet servo is at its minimum travel (tight). This is used when sailing "Close-Hauled" (upwind) to generate maximum lift from the sail.

*   **Standard Setting:** 0 degrees (Boom is perfectly aligned with the boat).

## Tuning & Behavior
*   **Default:** 0.
*   **Measurement:** Tighten your mainsheet completely and measure the angle. If your mechanical setup doesn't allow the boom to reach the center (0°), enter the actual minimum angle here.