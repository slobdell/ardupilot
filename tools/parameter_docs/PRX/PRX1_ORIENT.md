---
layout: parameter
name: PRX1_ORIENT
display_name: Proximity Orientation (Sensor 1)
description: Defines the physical orientation of the proximity sensor.
default_value: 0
range: 0 1
units: 
group: PRX
visual_asset_id: prx_orientation_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Proximity/AP_Proximity_Params.cpp#L22
---

# Proximity Orientation (PRX1_ORIENT)

## Description
`PRX1_ORIENT` tells ArduPilot if your 360-degree Lidar is mounted normally or upside down.

*   **0: Default (Right-side up).**
*   **1: Upside Down.**

## Tuning & Behavior
*   **Default:** 0.
*   **Action:** If your obstacle avoidance seems to react to objects on the wrong side (left instead of right), your sensor might be mounted upside down without this parameter being set correctly.