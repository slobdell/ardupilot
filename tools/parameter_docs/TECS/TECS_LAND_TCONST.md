---
layout: parameter
name: TECS_LAND_TCONST
display_name: TECS Landing Time Constant
description: The time constant (in seconds) for the landing height demand filter.
default_value: 2.0
range: 0 5
units: s
group: TECS
visual_asset_id: tecs_land_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_TECS/AP_TECS.cpp#L100
---

# TECS Landing Time Constant (TECS_LAND_TCONST)

## Description
`TECS_LAND_TCONST` controls how aggressively the plane corrects altitude errors during landing.

*   **Higher Value:** Slower, smoother corrections. Better for calm weather.
*   **Lower Value:** Faster corrections. Better for turbulent conditions where the plane gets knocked off the glide slope.

## Tuning & Behavior
*   **Default Value:** 2.0 seconds.