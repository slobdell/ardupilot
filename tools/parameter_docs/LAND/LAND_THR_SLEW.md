---
layout: parameter
name: LAND_THR_SLEW
display_name: Landing Throttle Slew Rate
description: The maximum rate of change (percentage per second) for throttle during landing.
default_value: 0
range: 0 100
units: %/s
group: LAND
visual_asset_id: land_flare_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/Parameters.cpp#L100
---

# Landing Throttle Slew Rate (LAND_THR_SLEW)

## Description
`LAND_THR_SLEW` prevents the throttle from "pumping" during the approach.

If TECS is fighting turbulence, it might command rapid throttle changes. This parameter forces the throttle to change smoothly, which is better for scale aircraft and passenger comfort.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled/Use `THR_SLEW`).
*   **Recommendation:** Set to **20-30%** if you hear the motor surging on final approach.