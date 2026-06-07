---
layout: parameter
name: QWIK_DOUBLE_TIME
display_name: Quicktune Doubling Time
description: The time (in seconds) it takes for the tuning algorithm to double a parameter value during the test phase.
default_value: 10
range: 5 20
units: s
group: QWIK
visual_asset_id: quicktune_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Quicktune/AP_Quicktune.cpp#L39
---

# Quicktune Doubling Time (QWIK_DOUBLE_TIME)

## Description
`QWIK_DOUBLE_TIME` controls the "Aggression" of the tuning process.

It determines how fast the autopilot increases the PID gains while searching for the oscillation point. 

*   **Low Value (5s):** Fast tune. The gains increase rapidly. Good for experienced pilots and stable frames.
*   **High Value (20s):** Slow tune. Safer for large, heavy, or expensive drones where a sudden oscillation could be dangerous.

## Tuning & Behavior
*   **Default Value:** 10 seconds.
*   **Recommendation:** If you get "Attitude Error - Aborting" messages during tuning, increase this value to **15 or 20** to give the drone more time to stabilize between gain steps.