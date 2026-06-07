---
layout: parameter
name: Q_ASSIST_DELAY
display_name: QuadPlane Assist Delay
description: The delay (in seconds) before QuadPlane assistance activates after the airspeed drops below the threshold.
default_value: 0.5
range: 0 5
units: s
group: Q
visual_asset_id: vtol_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# QuadPlane Assist Delay (Q_ASSIST_DELAY)

## Description
`Q_ASSIST_DELAY` filters out momentary noise. 

If the airspeed drops below `Q_ASSIST_SPEED` for just a split second (e.g., due to a sensor glitch or a gust of wind), we don't want the loud VTOL motors to scream to life immediately. This parameter ensures the low speed condition is real.

## Tuning & Behavior
*   **Default Value:** 0.5 seconds.
*   **Recommendation:** Leave at **0.5**.