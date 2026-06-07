---
layout: parameter
name: TECS_FLARE_HGT
display_name: Flare Height
description: The height (in meters) at which the landing flare maneuver begins.
default_value: 1.0
range: 0 15
units: m
group: TECS
visual_asset_id: tecs_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_TECS/AP_TECS.cpp#L275
---

# Flare Height (TECS_FLARE_HGT)

## Description
`TECS_FLARE_HGT` defines the start of the "Touchdown" phase during an autonomous landing.

When the drone's altitude above the ground (via rangefinder) drops below this value, the autopilot enters the "Flare" state. In this state, it stops following the steep glide slope and instead tries to maintain a very gentle descent rate (`TECS_LAND_SINK`) while raising the nose to bleed off airspeed.

*   **Standard Setting:** 1.0 to 2.0 meters.

## Tuning & Behavior
*   **Default:** 1.0.
*   **Too Low:** The plane might hit the ground too hard before it has a chance to slow down.
*   **Too High:** The plane will "float" along the runway for a long time, potentially running out of space.
*   **Dependencies:** Requires an enabled and functional rangefinder ([RNGFND_LANDING](RNGFND_LANDING.html)).