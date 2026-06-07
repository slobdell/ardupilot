---
layout: parameter
name: PRX1_YAW_CORR
display_name: Proximity Sensor Yaw Correction
description: Sets the yaw offset (in degrees) for the proximity sensor to align its "Forward" with the vehicle's forward axis.
default_value: 0
range: -180 180
units: deg
group: PRX
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Proximity/AP_Proximity_Params.cpp#L30
---

# Proximity Sensor Yaw Correction (PRX1_YAW_CORR)

## Description
`PRX1_YAW_CORR` allows you to digitally "Rotate" your proximity sensor if it wasn't mounted perfectly straight.

For obstacle avoidance to work, the autopilot must know exactly which direction each sensor reading corresponds to. If your Lidar is mounted 90 degrees to the right, you set this to 90 so the autopilot knows to shift all incoming data accordingly.

## Tuning & Behavior
*   **Default:** 0.
*   **Calibration:** Point your drone at a known obstacle (like a wall) and check the proximity radar in your GCS. If the wall appears to the side instead of directly in front, adjust this parameter until they match.
*   **Significance:** Critical for accurate avoidance maneuvers; if this is off, the drone might steer *into* an obstacle while trying to avoid it.