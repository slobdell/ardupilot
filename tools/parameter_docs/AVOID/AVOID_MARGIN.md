---
layout: parameter
name: AVOID_MARGIN
display_name: Avoidance distance margin
description: The minimum distance (in meters) the vehicle attempts to maintain from any obstacle.
default_value: 2.0
range: 1.0 10.0
units: m
group: AVOID
visual_asset_id: avoid_margin_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_Avoidance/AC_Avoid.cpp#L65
---

# Avoidance distance margin (AVOID_MARGIN)

## Description
`AVOID_MARGIN` is the "Social Distancing" rule for your drone. It defines how close the drone is allowed to get to a wall or obstacle before the avoidance logic kicks in.

*   **2.0 (Default):** The drone will try to stay at least 2 meters away from everything.

## The Mathematics
The desired velocity is scaled by the distance to the obstacle $d$ using a square-root deceleration curve:
$$ v_{max} = \sqrt{2 \cdot \text{AVOID\_ACCEL\_MAX} \cdot (d - \text{AVOID\_MARGIN})} $$

If $d \leq \text{AVOID\_MARGIN}$, $v_{max} = 0$ (The drone stops).

## Tuning & Behavior
*   **Default Value:** 2.0 meters
*   **Recommendation:** 
    *   **Indoors:** Decrease to **0.5m or 1.0m** to allow flying through doorways.
    *   **Outdoors:** Keep at **2.0m**. This provides enough reaction time for the Lidar to see small objects like branches.
*   **Latency:** If your sensor has high latency (e.g., a slow spinning Lidar), you must increase this margin.