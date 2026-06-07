---
layout: parameter
name: ZIGZ_WP_DELAY
display_name: ZigZag Waypoint Delay
description: The pause time (in seconds) at each end-point (A and B) before starting the next leg.
default_value: 0
range: 0 127
units: s
group: ZIGZ
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduCopter/mode_zigzag.cpp#L35
---

# ZigZag Waypoint Delay (ZIGZ_WP_DELAY)

## Description
`ZIGZ_WP_DELAY` introduces a pause at the turn-around points.

When the drone reaches point A or point B in ZigZag mode, it will wait for this many seconds before stepping sideways and continuing to the next leg. This is useful for allowing mechanical equipment (like a sprayer pump) to fully cycle or for the drone's attitude to stabilize before the next movement.

## Tuning & Behavior
*   **Default:** 0 seconds.
*   **Recommendation:** Use **1 or 2 seconds** if you notice the drone's "Zig" and "Zag" legs aren't perfectly parallel due to aggressive turn-around maneuvers.