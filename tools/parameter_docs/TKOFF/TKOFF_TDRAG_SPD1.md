---
layout: parameter
name: TKOFF_TDRAG_SPD1
display_name: Tail-Dragger Tail-Lift Airspeed
description: The airspeed (in m/s) at which the tail should lift off the ground during an autonomous takeoff roll.
default_value: 0
range: 0 30.0
units: m/s
group: TKOFF
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduPlane/Parameters.cpp#L184
---

# Tail-Dragger Tail-Lift Airspeed (TKOFF_TDRAG_SPD1)

## Description
`TKOFF_TDRAG_SPD1` automates the specific takeoff physics of a **Tail-Dragger** airplane.

Tail-draggers require the pilot to hold "Full Up" elevator early in the takeoff roll to keep the tailwheel pinned for steering. Once enough speed is gained for the rudder to become effective, the tail must be allowed to lift so the plane can accelerate in a level attitude. This parameter defines that transition speed.

*   **0:** Disabled. Use for tricycle gear or hand-launches.
*   **Value (m/s):** The airspeed at which the autopilot relaxes the "Up" elevator and levels the fuselage.

## Tuning & Behavior
*   **Recommendation:** Set this to slightly below the stall speed of your aircraft.
*   **Sequence:** 
    1.  Ground roll starts with tail held down.
    2.  At `TKOFF_TDRAG_SPD1`, tail lifts and plane rolls on main wheels only.
    3.  At `TKOFF_ROTATE_SPD`, the plane pitches up and climbs.
*   **Benefit:** Ensures stable, straight-line takeoff rolls without the aircraft "nosing over" or bouncing.