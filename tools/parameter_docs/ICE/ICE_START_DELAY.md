---
layout: parameter
name: ICE_START_DELAY
display_name: Time to wait between starts
description: The pause (in seconds) between consecutive cranking attempts.
default_value: 2
range: 1 10
units: s
group: ICE
visual_asset_id: ice_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_ICEngine/AP_ICEngine.cpp#L61
---

# Time to wait between starts (ICE_START_DELAY)

## Description
`ICE_START_DELAY` is a cooldown and recovery timer for the engine start sequence.

After a failed start attempt, the autopilot waits for this duration before trying again. This delay protects the starter motor from over-working and allows the fuel system to re-prime if necessary.

## Tuning & Behavior
*   **Default Value:** 2 seconds.
*   **Recommendation:** Set high enough to allow the starter motor to stop spinning completely before the next engagement.