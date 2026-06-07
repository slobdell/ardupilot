---
layout: parameter
name: TECS_PTCH_DAMP
display_name: Pitch Damping Gain
description: The damping gain for the pitch control loop in TECS. Prevents the nose from oscillating when correcting for altitude or speed errors.
default_value: 0.3
range: 0.1 1.0
units: 
group: TECS
visual_asset_id: tecs_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_TECS/AP_TECS.cpp#L110
---

# Pitch Damping Gain (TECS_PTCH_DAMP)

## Description
`TECS_PTCH_DAMP` prevents the plane from "Nodding" its head.

When the autopilot commands a pitch change to maintain height, it needs to stop that movement at the right time. Damping provides the "Brakes" for the pitch maneuver.

*   **Higher Value:** Less oscillation, but too high can cause the pitch to be sluggish and unresponsive.
*   **Lower Value:** More active pitch, but can lead to a "Porpoising" motion where the drone constantly bobs up and down.
