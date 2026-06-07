---
layout: parameter
name: LAND_SPEED
display_name: Land Descent Speed
description: The vertical speed (in cm/s) for the final stage of an automatic landing.
default_value: 50
range: 30 200
units: cm/s
group: LAND
visual_asset_id: land_speed_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduCopter/Parameters.cpp#L100
---

# Land Descent Speed (LAND_SPEED)

## Description
`LAND_SPEED` is the "Final Contact Speed" for the drone. It is the vertical velocity used from `LAND_ALT_LOW` until the drone detects it has touched the ground.

## The Engineer's View
In the ArduCopter control loop, once the `LAND_ALT_LOW` threshold is crossed, the position controller switches to a target velocity equal to this parameter. The "Land Detector" state machine then waits for:
1.  **Vertical Velocity** to be near zero.
2.  **Throttle** to be at minimum.
Once these are met for a specific duration (`LAND_DISARMDELAY`), the drone disarms.

## Tuning & Behavior
*   **Default Value:** 50 cm/s (0.5 m/s).
*   **The "Bounce" Issue:** If your drone bounces back into the air upon touching down, your `LAND_SPEED` is likely too high, or your landing gear is too springy. Reduce to **30-40 cm/s**.
*   **Surface Consistency:** If landing on tall grass or soft sand, you may need a slightly higher speed to ensure the land detector triggers reliably.