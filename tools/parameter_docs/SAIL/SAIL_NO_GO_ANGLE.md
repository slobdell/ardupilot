---
layout: parameter
name: SAIL_NO_GO_ANGLE
display_name: Sail No-Go Zone Angle
description: The closest angle to the wind (in degrees) that the boat can efficiently sail.
default_value: 45
range: 30 60
units: deg
group: SAIL
visual_asset_id: sailboat_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/Rover/sailboat.cpp#L76
---

# Sail No-Go Zone Angle (SAIL_NO_GO_ANGLE)

## Description
`SAIL_NO_GO_ANGLE` defines the "Upwind Limit" of your boat.

A sailboat cannot sail directly into the wind; if it tries, the sails will simply luff (flap) and the boat will stop. This parameter defines the boundary of that unusable sector. When the autopilot needs to reach a waypoint that is directly upwind, it will use this angle to calculate the "Tacks" (zig-zagging) required to get there.

## Tuning & Behavior
*   **Default:** 45 degrees.
*   **High Performance:** For a fast racing yacht with high-quality sails, you can decrease this to **35** or **40** degrees.
*   **Casual/Draggy:** For a bulky boat or one with less efficient sails, you might need to increase this to **50** or **55** degrees.
*   **Effect:** If this value is too low, the boat will constantly lose speed and "Stall" while trying to point too high into the wind. If too high, the boat will be inefficient and take much longer to reach upwind targets.