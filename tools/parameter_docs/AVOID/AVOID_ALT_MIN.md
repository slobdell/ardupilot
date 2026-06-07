---
layout: parameter
name: AVOID_ALT_MIN
display_name: Avoidance Minimum Altitude
description: The altitude (in meters) below which obstacle avoidance is automatically disabled to allow for landing.
default_value: 0
range: 0 10
units: m
group: AVOID
visual_asset_id: avoid_logic_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_Avoidance/AC_Avoid.cpp#L101
---

# Avoidance Minimum Altitude (AVOID_ALT_MIN)

## Description
`AVOID_ALT_MIN` prevents the drone from freaking out near the ground.

Proximity sensors (like 360 Lidar) often detect the ground as an "obstacle" when landing or taking off. If avoidance stays active, the drone might refuse to land because it thinks the floor is a wall. This parameter sets a floor altitude where avoidance is turned off.

*   **Default Value:** 0 (Disabled).
*   **Recommendation:** Set to **1.0 or 2.0 meters**.

## The Engineer's View
Used in `AC_Avoid::adjust_velocity`. If `current_alt < alt_min`, the velocity modification logic is bypassed.

## Tuning & Behavior
*   **Safety:** Always set this if you have downward-angled sensors or if you fly in tall grass.