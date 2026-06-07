---
layout: parameter
name: PRX_ALT_MIN
display_name: Proximity Minimum Altitude
description: Minimum altitude (relative to home) before proximity avoidance becomes active.
default_value: 1.0
range: 0 10
units: m
group: PRX
visual_asset_id: prx_ignore_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Proximity/AP_Proximity.cpp#L80
---

# Proximity Minimum Altitude (PRX_ALT_MIN)

## Description
`PRX_ALT_MIN` defines the "Activation Floor" for object avoidance. 

Proximity sensors (like 360-degree Lidars) can sometimes "see" the ground when the drone is very low or during takeoff/landing, causing false obstacle detections. This parameter tells the autopilot to ignore all proximity data until the drone has climbed above this altitude.

*   **Default Value:** 1.0 meter.
*   **Safety:** This ensures the drone doesn't try to "dodge" the grass or its own landing pad during the critical phases of flight.

## Tuning & Behavior
*   **Default:** 1.0.
*   **Note:** This requires a valid downward-facing Rangefinder (Lidar/Sonar) to know the altitude accurately. If no rangefinder is present, this parameter may not function as expected.