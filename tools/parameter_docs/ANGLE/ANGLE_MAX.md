---
layout: parameter
name: ANGLE_MAX
display_name: maximum angle error for tune abort
description: If while tuning the angle error goes over this limit then the tune will aborts to prevent a bad oscillation in the case of the tuning algorithm failing.
default_value: 10
range: 
units: deg
group: ANGLE
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Quicktune/AP_Quicktune.cpp
---

# maximum angle error for tune abort (ANGLE_MAX)

## Description
Safety threshold for Quicktune. If the aircraft's attitude deviates more than this from the target during tuning, the process will immediately abort to prevent potential crashes from unstable PID gains.

## Tuning & Behavior
*   **Default Value:** 10 deg
*   **If you get "Quicktune: attitude error ABORTING" frequently, ensure the aircraft is well-balanced or slightly increase this value.**