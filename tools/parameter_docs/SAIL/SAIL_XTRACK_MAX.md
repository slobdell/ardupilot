---
layout: parameter
name: SAIL_XTRACK_MAX
display_name: Sailboat Max Cross-Track Error
description: The maximum distance the boat is allowed to deviate from its path before it is forced to tack.
default_value: 10
range: 5 50
units: m
group: SAIL
visual_asset_id: sailboat_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/Rover/sailboat.cpp#L94
---

# Sailboat Max Cross-Track Error (SAIL_XTRACK_MAX)

## Description
`SAIL_XTRACK_MAX` defines the "Corridor Width" for sailing missions.

When sailing upwind, a boat must zig-zag (tack) to reach its target. This parameter sets how far the boat can move to either side of the direct line (the "Cross-Track") before the autopilot triggers a tack to come back toward the center. 

*   **Default:** 10 meters.
*   **Recommendation:** For large open water, you can increase this to **20 or 30** meters to reduce the number of tacks and improve efficiency. For narrow channels, keep it at **5 or 10**.