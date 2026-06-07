---
layout: parameter
name: SAIL_LOIT_RADIUS
display_name: Sail Loiter Radius
description: The minimum radius used for sailboat loitering and station-keeping.
default_value: 5
range: 0 50
units: m
group: SAIL
visual_asset_id: sailboat_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/Rover/sailboat.cpp#L103
---

# Sail Loiter Radius (SAIL_LOIT_RADIUS)

## Description
`SAIL_LOIT_RADIUS` defines the size of the "Waiting Area" for a sailboat.

Since a sailboat cannot simply stop and hover (unless it drops an anchor), it "Loiters" by sailing in a continuous circle or figure-eight pattern. This parameter sets the radius of that pattern.

## Tuning & Behavior
*   **Default:** 5 meters.
*   **Recommendation:** Set this to a value at least **3 to 5 times** the length of your boat. If the radius is too small, the boat will spend all its time turning (tacking) and may lose momentum and get stuck.
*   **Safety:** Ensure the radius is large enough for the boat to successfully complete a turn (tack or jibe) without exiting the loiter boundary.