---
layout: parameter
name: SOAR_VSPEED
display_name: Soaring Vertical Speed Trigger
description: The climb rate (in m/s) required to trigger the transition from cruise to thermalling mode.
default_value: 0.7
range: 0 10
units: m/s
group: SOAR
visual_asset_id: soaring_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Soaring/AP_Soaring.cpp#L26
---

# Soaring Vertical Speed Trigger (SOAR_VSPEED)

## Description
`SOAR_VSPEED` is the "Excitement Threshold" for your glider. 

It defines how strong a thermal must be before the drone decides to stop its mission and start circling. If the "Nettorate" (the vertical speed of the air around the plane, with the plane's own sink rate removed) exceeds this value, the drone declares "Lift Detected!"

*   **Low Value (e.g. 0.5):** Very sensitive. The drone will try to circle in almost any rising air.
*   **High Value (e.g. 2.0):** Selective. The drone only stops for strong, reliable thermals.

## Tuning & Behavior
*   **Default Value:** 0.7 m/s.
*   **Recommendation:** Match this to your glider's performance. A high-performance carbon glider might circle in **0.5m/s**, while a draggy foam glider might need **1.0m/s** to make any real progress.