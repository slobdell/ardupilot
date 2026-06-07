---
layout: parameter
name: LAND_OPTIONS
display_name: Landing Options
description: A bitmask of options to modify fixed-wing landing behavior.
default_value: 0
range: 0 7
units: 
group: LAND
visual_asset_id: land_flare_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/Parameters.cpp#L100
---

# Landing Options (LAND_OPTIONS)

## Description
`LAND_OPTIONS` tweaks the landing logic.

*   **Bit 0:** Use Rangefinder for Flare. Requires a Lidar. Much more precise than Baro.
*   **Bit 1:** Idle throttle during Pre-Flare.

## Tuning & Behavior
*   **Default Value:** 0.