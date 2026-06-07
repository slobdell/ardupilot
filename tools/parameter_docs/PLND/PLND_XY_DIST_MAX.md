---
layout: parameter
name: PLND_XY_DIST_MAX
display_name: Precision Land Maximum Start Distance
description: The maximum horizontal distance (in meters) the vehicle is allowed to be from the target before it begins its vertical descent.
default_value: 2.5
range: 0 10.0
units: m
group: PLND
visual_asset_id: precland_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PrecLand/AC_PrecLand.cpp#L104
---

# Precision Land Maximum Start Distance (PLND_XY_DIST_MAX)

## Description
`PLND_XY_DIST_MAX` is a "Descent Lock." 

When the drone arrives at the landing site and sees the target, it must first align itself horizontally. If the drone is too far to the side (e.g. 5 meters away), starting the descent would cause it to land at an angle or miss the pad. 

This parameter tells the drone: "Do not start moving down until you are within **X meters** of the center of the target."

*   **Default Value:** 2.5 meters.
*   **Safety:** Setting this to **0** disables the check, and the drone will descend immediately while still trying to fix its horizontal position.

## The Engineer's View
Used in the Precision Landing state machine. While the horizontal error is greater than this value, the vertical velocity demand is held at 0 (or a very low "Wait" value). Once the error drops below the threshold, the `Land` stage is permitted to proceed with its standard vertical descent profile.

## Tuning & Behavior
*   **Default Value:** 2.5m.
*   **Precision:** If you have a very small landing pad (e.g. 1 meter wide), decrease this to **1.0m** to ensure a perfectly centered approach.
*   **Windy Sites:** If the wind is strong and the drone is struggling to get perfectly centered, increase this to **4.0m** to prevent the drone from "hanging" indefinitely at height.