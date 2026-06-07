---
layout: parameter
name: TECS_PITCH_MAX
display_name: Maximum Pitch in Auto Flight
description: The maximum allowed pitch angle (in degrees) that the TECS controller can demand during autonomous flight modes.
default_value: 15
range: 0 45
units: deg
group: TECS
visual_asset_id: tecs_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_TECS/AP_TECS.cpp#L154
---

# Maximum Pitch in Auto Flight (TECS_PITCH_MAX)

## Description
`TECS_PITCH_MAX` acts as a "Nose Limiter" for autonomous flight.

While the global `PTCH_LIM_MAX` sets the hard physical limit for the whole aircraft, `TECS_PITCH_MAX` is used specifically by the climb controller. It ensures that the drone doesn't point its nose so steeply into the sky that it loses all its airspeed, even if the flight controller thinks it needs to climb faster.

## Tuning & Behavior
*   **Default Value:** 15°.
*   **Recommendation:** Set to the angle your plane can comfortably sustain at full throttle without losing airspeed.
*   **Gliders:** Can be set higher (25°) for aggressive climbing.
*   **Heavy Cargo:** Set lower (10°) to ensure the plane always keeps the nose down enough for speed.