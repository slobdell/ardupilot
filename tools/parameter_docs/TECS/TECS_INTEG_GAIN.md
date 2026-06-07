---
layout: parameter
name: TECS_INTEG_GAIN
display_name: TECS Integrator Gain
description: The integrator gain for the TECS control loop. Corrects for long-term altitude and speed offsets.
default_value: 0.1
range: 0 0.5
units: 
group: TECS
visual_asset_id: tecs_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_TECS/AP_TECS.cpp#L105
---

# TECS Integrator Gain (TECS_INTEG_GAIN)

## Description
`TECS_INTEG_GAIN` handles "Persistence."

If the plane is consistently flying 5 meters below the target altitude, the I-term builds up more throttle or pitch to force it up to the correct height. 

## Tuning & Behavior
*   **Default Value:** 0.1.
*   **Too High:** The plane will overshoot its target and then oscillate up and down slowly.
*   **Too Low:** The plane will stay slightly below its target altitude or above its target speed indefinitely.
