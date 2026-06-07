---
layout: parameter
name: TERRAIN_LOOKAHD
display_name: Terrain Look-Ahead Distance
description: The distance (in meters) the autopilot looks ahead to anticipate rising terrain.
default_value: 2000
range: 0 5000
units: m
group: TERRAIN
visual_asset_id: terrain_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduPlane/Parameters.cpp#L344
---

# Terrain Look-Ahead Distance (TERRAIN_LOOKAHD)

## Description
`TERRAIN_LOOKAHD` allows the drone to see a mountain coming and start climbing *before* it gets there.

Without look-ahead, the drone would only react to the ground directly beneath it. If it flew toward a steep cliff, it might not have enough time to climb over it. This parameter tells the navigation controller to scan the terrain map ahead of the current position. If it sees a hill coming, it will begin the climb early to ensure a safe and smooth clearance.

## Tuning & Behavior
*   **Default:** 2000 meters.
*   **Recommendation:**
    *   **Fast Planes:** Keep at **2000m** or more. You need time to climb.
    *   **Slow Copters:** You can reduce this to **500m** or **1000m**, as copters can climb vertically if needed.
*   **Note:** The look-ahead never extends past the *next* waypoint.