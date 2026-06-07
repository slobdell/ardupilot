---
layout: parameter
name: LAND_ALT_LOW
display_name: Land Altitude Low
description: The altitude (in meters) at which the vehicle will slow down its descent speed for final touchdown.
default_value: 10
range: 0 30
units: m
group: LAND
visual_asset_id: land_alt_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduCopter/Parameters.cpp#L100
---

# Land Altitude Low (LAND_ALT_LOW)

## Description
`LAND_ALT_LOW` determines the "Slow Down Height" for automatic landings. 

When a drone is landing automatically (e.g., during a Return-to-Launch), it usually descends quickly to save battery. However, descending fast into the ground would cause a crash. `LAND_ALT_LOW` sets the altitude where the drone transitions from a fast "Transit Descent" to a slow, gentle "Touchdown Descent."

## The Mathematics
The autopilot manages the descent rate ($v_z$) based on the current altitude ($h$):

*   If $h > \text{LAND_ALT_LOW}$, $v_z = \text{WPNAV_SPEED_DN}$.
*   If $h \le \text{LAND_ALT_LOW}$, $v_z$ is linearly ramped down until it reaches `LAND_SPEED` at the ground.

## The Engineer's View
Defined in the vehicle-specific `Parameters.cpp` (e.g., `ArduCopter`).
This parameter is critical for preventing "ground effect" instability. If the drone descends too fast into its own propwash near the ground, it can wobble or lose control. By slowing down at a specific height, the flight controller has more time to stabilize the airframe before contact.

## Tuning & Behavior
*   **Default Value:** 10 meters.
*   **High Performance:** For large industrial drones, you may want to increase this to **15 or 20 meters** to ensure a very stable approach.
*   **Small Quads:** For racing or small freestyle quads, you can lower this to **5 meters** for a faster recovery.