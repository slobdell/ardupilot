---
layout: parameter
name: QWIK_ANGLE_MAX
display_name: Quicktune Max Attitude Error
description: The attitude error threshold (in degrees) that will cause the tuning process to abort for safety.
default_value: 10
range: 0 45
units: deg
group: QWIK
visual_asset_id: quicktune_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Quicktune/AP_Quicktune.cpp#L112
---

# Quicktune Max Attitude Error (QWIK_ANGLE_MAX)

## Description
`QWIK_ANGLE_MAX` is the "Emergency Kill Switch" for the tuning process.

If the drone's actual tilt angle differs from your stick command by more than this many degrees (indicating that the drone is losing control or oscillating wildly), Quicktune will instantly abort the tune and revert to your original safe gains.

## Tuning & Behavior
*   **Default Value:** 10 degrees.
*   **Recommendation:** If you get "Attitude Error - Aborting" messages during tuning even when the drone seems stable, try increasing this to **15 or 20**.
*   **Safety:** Do not set this too high (e.g. >30), as it protects the drone from a bad tune that could lead to a crash.