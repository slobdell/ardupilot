---
layout: parameter
name: PRX1_MIN
display_name: Proximity Minimum Range (Sensor 1)
description: The minimum distance (in meters) the proximity sensor can reliably see obstacles.
default_value: 0
range: 0 500
units: m
group: PRX
visual_asset_id: prx_range_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Proximity/AP_Proximity_Params.cpp#L102
---

# Proximity Minimum Range (PRX1_MIN)

## Description
`PRX1_MIN` defines the "Blind Spot" around your drone. 

If the sensor reports an object closer than this value, the autopilot ignores it. This is critical to prevent the drone from being "scared" of its own frame, propellers, or mounting brackets if they are within the sensor's field of view.

*   **0: Use sensor default.** (Recommended).
*   **Value (m):** Set this to slightly more than the distance from the sensor to the edge of your drone's props.

## Tuning & Behavior
*   **Default:** 0.
*   **Safety:** Setting this too low may cause the drone to detect its own frame as an obstacle, preventing it from moving.