---
layout: parameter
name: LAND_SPEED_HIGH
display_name: Land Descent Speed High
description: The vertical speed (in cm/s) for the initial stage of an automatic landing, before the vehicle reaches LAND_ALT_LOW.
default_value: 0
range: 0 500
units: cm/s
group: LAND
visual_asset_id: land_speed_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduCopter/Parameters.cpp#L100
---

# Land Descent Speed High (LAND_SPEED_HIGH)

## Description
`LAND_SPEED_HIGH` allows the drone to descend faster from high altitudes during an RTL or LAND mission, then slow down once it gets closer to the ground.

*   **0 (Default):** The drone uses the standard `WPNAV_SPEED_DN` for the entire descent until `LAND_ALT_LOW`.
*   **Value (e.g., 200):** The drone will descend at 2 m/s until it hits the low altitude threshold.

## Tuning & Behavior
*   **Default Value:** 0
*   **Recommendation:** If you frequently fly at high altitudes (e.g., 100m+), set this to **200 or 300** to save battery during RTL.