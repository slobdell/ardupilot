---
layout: parameter
name: PRX1_MAX
display_name: Proximity Maximum Range (Sensor 1)
description: The maximum distance (in meters) the proximity sensor can reliably see obstacles.
default_value: 0
range: 0 500
units: m
group: PRX
visual_asset_id: prx_range_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Proximity/AP_Proximity_Params.cpp#L110
---

# Proximity Maximum Range (PRX1_MAX)

## Description
`PRX1_MAX` defines the "Horizon" for your drone's obstacle avoidance system. 

If the sensor reports an object farther away than this value, the autopilot ignores it. This is important to filter out noise at the edge of the sensor's capability or to ignore distant objects that aren't a threat.

*   **0: Use sensor default.** (Recommended for most digital sensors).
*   **1-500: Range in meters.**

## Tuning & Behavior
*   **Default:** 0.
*   **Recommendation:** If you notice your drone "jerking" or reacting to "ghost" obstacles in the distance, set this to **80%** of the sensor's physical max range (e.g., set to 16 for a 20m Lidar).