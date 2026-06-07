---
layout: parameter
name: ZIGZ_SIDE_DIST
display_name: ZigZag Mode Step Distance
description: The lateral distance (in meters) to move at the end of each "Zig" or "Zag" leg.
default_value: 4.0
range: 0.1 100.0
units: m
group: ZIGZ
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduCopter/mode_zigzag.cpp#L43
---

# ZigZag Mode Step Distance (ZIGZ_SIDE_DIST)

## Description
`ZIGZ_SIDE_DIST` defines the "Width" of your scanning pattern. 

In **ZigZag** mode (commonly used for agricultural crop spraying), the pilot defines two points (A and B). The drone flies back and forth between these points. When it reaches one end, the pilot can command a "Step" to the side. This parameter sets how many meters the drone moves sideways for each of those steps.

## Tuning & Behavior
*   **Default:** 4.0 meters.
*   **Recommendation:** Set this to the effective width of your spraying boom or the "swath" of your sensor to ensure 100% coverage with no gaps or excessive overlaps.