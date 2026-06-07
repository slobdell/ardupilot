---
layout: parameter
name: TECS_LAND_THR
display_name: Cruise Throttle During Landing
description: The throttle percentage used during landing approach if no airspeed sensor is present.
default_value: -1
range: -1 100
units: '%'
group: TECS
visual_asset_id: landing_path_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_TECS/AP_TECS.cpp#L138
---

# Cruise Throttle During Landing (TECS_LAND_THR)

## Description
`TECS_LAND_THR` is for planes **without** an airspeed sensor.

Normally, TECS calculates the throttle needed to maintain landing speed. If there is no speed sensor, it can't do that. This parameter allows you to hard-code a fixed throttle percentage (e.g. 40%) that you know is safe for a slow descent on your specific airframe.

*   **-1 (Default):** Disabled (Use speed-based calculation).
*   **45:** Hold 45% throttle during the entire landing approach.

## Tuning & Behavior
*   **Default Value:** -1.
*   **Recommendation:** If you don't have an airspeed sensor, set this to the lowest throttle that keeps your plane flying safely above stall speed (e.g. 35-45%).
