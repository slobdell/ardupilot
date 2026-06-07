---
layout: parameter
name: MIN_REVERSE_TIME
display_name: "Minimum time to apply a yaw reversal"
description: "Minimum duration to drive the yaw servo in reverse when a limit is hit"
default_value: 1
range: 0 20
units: "s"
group: MIN
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/AntennaTracker/Parameters.cpp#L62
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Minimum time to apply a yaw reversal (MIN_REVERSE_TIME)

## Description
This parameter is specific to Antenna Trackers with mechanical stops (non-continuous rotation). When the tracker hits its yaw limit (e.g., 360 degrees), it must stop and reverse direction ("unwind") to re-acquire the target. This parameter forces the unwinding motion to continue for a minimum duration, preventing the tracker from getting stuck toggling back and forth at the limit.

## The Mathematics
Hysteresis Timer:
$$ \text{If } (\text{Limit Hit}) \implies \text{Reverse State} = \text{True} $$
$$ \text{If } (\text{Time in Reverse} < \text{MIN_REVERSE_TIME}) \implies \text{Keep Reversing} $$

## The Engineer's View
Defined in `AntennaTracker/Parameters.cpp`. Handles the "Unwrap" logic for servos.
*   **Lag Compensation:** Mechanical systems have inertia and lag; this timer ensures the movement is significant enough to clear the stop.

## Tuning & Behavior
*   **Default Value:** 1 s
*   **Increase:** If the tracker "chatters" or oscillates at the end-stop.