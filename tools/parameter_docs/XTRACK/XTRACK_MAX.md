---
default_value: 10
description: The sail boat will tack when it reaches this cross track error, defines
  a corridor of 2 times this value wide, 0 disables
display_name: Sailing vehicle max cross track error
group: XTRACK
investigation_status: complete
layout: parameter
name: XTRACK_MAX
range: 5 25
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/Rover/sailboat.cpp#L94
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/Rover/sailboat.h#L108
units: m
visual_asset_id: null
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Sailing vehicle max cross track error (XTRACK_MAX)

## Description
This parameter defines the width of the "Sailing Corridor" for autonomous sailboats. When sailing upwind (into the wind), the boat must zigzag (tack) to reach its destination.

`XTRACK_MAX` sets the maximum allowable distance the boat can drift from the direct line to the waypoint before it is forced to tack (turn 90 degrees) to get back on course.

## The Mathematics
This parameter effectively creates a virtual hallway of width $2 \times XTRACK\_MAX$ centered on the line between the previous and next waypoint.

$$ \text{Trigger Tack IF: } |CrossTrackError| \ge XTRACK\_MAX $$

The logic also checks the wind direction to ensure the tack will actually reduce the error (i.e., turning *towards* the center line, not away).

## The Engineer's View
In `Sailboat::calc_heading()` (`Rover/sailboat.cpp`):
1.  The function computes `cross_track_error` using the navigation library.
2.  It checks `if ((fabsf(cross_track_error) >= xtrack_max) && ...`.
3.  If triggered, `should_tack` becomes `true`.
4.  If the boat is on Starboard tack and error is positive (right side of corridor), it tacks to Port.
5.  If on Port tack and error is negative (left side of corridor), it tacks to Starboard.

## Tuning & Behavior
*   **Default Value:** 10 meters
*   **Range:** 5 to 25 meters
*   **Effect of Increasing:** The boat will tack less frequently, making longer legs. This is generally more efficient as tacking slows the boat down.
*   **Effect of Decreasing:** The boat will stay very close to the direct path, tacking frequently. This is useful in narrow channels but inefficient in open water.
*   **0:** Disables auto-tacking based on crosstrack error.
