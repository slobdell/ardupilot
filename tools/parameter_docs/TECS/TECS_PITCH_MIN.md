---
layout: parameter
name: TECS_PITCH_MIN
display_name: Minimum Pitch in Auto Flight
description: The minimum allowed pitch angle (in degrees) that the TECS controller can demand during autonomous flight modes.
default_value: 0
range: -45 0
units: deg
group: TECS
visual_asset_id: tecs_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_TECS/AP_TECS.cpp#L159
---

# Minimum Pitch in Auto Flight (TECS_PITCH_MIN)

## Description
`TECS_PITCH_MIN` prevents the drone from "Diving" too steeply when it needs to lose altitude.

*   **0 (Default):** The drone will not point its nose down during autonomous flight. It will only descend by reducing throttle.
*   **-10:** The drone can point its nose 10° down to help reach its target altitude faster.

## Tuning & Behavior
*   **Default Value:** 0.
*   **Recommendation:** Use **-5 or -10** if you find the drone "Over-climbs" and takes too long to get back down to its target altitude.