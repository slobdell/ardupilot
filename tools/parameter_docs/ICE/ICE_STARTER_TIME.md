---
layout: parameter
name: ICE_STARTER_TIME
display_name: Time to run starter
description: The duration (in seconds) the starter motor is engaged during each start attempt.
default_value: 3
range: 0.1 5.0
units: s
group: ICE
visual_asset_id: ice_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_ICEngine/AP_ICEngine.cpp#L53
---

# Time to run starter (ICE_STARTER_TIME)

## Description
`ICE_STARTER_TIME` sets the "Cranking Duration."

It defines how long the starter motor remains powered during a start attempt. If the engine reaches the `ICE_RPM_THRESH` before this timer expires, the starter is immediately disengaged. If the timer expires and the engine is not running, the system will wait (`ICE_START_DELAY`) and then try again.

## Tuning & Behavior
*   **Default Value:** 3 seconds.
*   **Recommendation:** Set to the minimum time required for your engine to fire and reach a self-sustaining RPM. Cranking for too long can overheat the starter motor or drain the battery.