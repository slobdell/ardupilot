---
layout: parameter
name: ICE_IDLE_PCT
display_name: Throttle Percentage for Engine Idle
description: The minimum throttle floor (in percent) maintained while the engine is running.
default_value: 0
range: 0 100
units: %
group: ICE
visual_asset_id: ice_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_ICEngine/AP_ICEngine.cpp#L112
---

# Throttle Percentage for Engine Idle (ICE_IDLE_PCT)

## Description
`ICE_IDLE_PCT` sets the "Floor" for the throttle command.

Once the engine is running, the autopilot will never drop the throttle below this value, even if the mission commands 0% thrust. This prevents the engine from stalling (dying) during low-power segments of a flight, such as a steep descent or landing approach.

## Tuning & Behavior
*   **Default Value:** 0%.
*   **Recommendation:** Set this to the lowest throttle percentage that results in a reliable, steady idle.
*   **Interaction:** If `ICE_IDLE_RPM` is also set, the autopilot will use the governor to dynamically adjust this floor.