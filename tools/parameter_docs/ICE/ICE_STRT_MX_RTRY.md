---
layout: parameter
name: ICE_STRT_MX_RTRY
display_name: Maximum Number of Retries
description: The maximum number of automated cranking attempts before the system gives up and declares a failure.
default_value: 0
range: 0 127
units: 
group: ICE
visual_asset_id: ice_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_ICEngine/AP_ICEngine.cpp#L148
---

# Maximum Number of Retries (ICE_STRT_MX_RTRY)

## Description
`ICE_STRT_MX_RTRY` prevents the drone from burning out its starter motor or draining its battery on a stubborn engine.

If the engine fails to start after a series of attempts, this parameter sets the limit. Once reached, the autopilot stops trying and sends a "Critical: Engine failed to start" message to the GCS.

*   **0 (Default):** Infinite retries.
*   **3:** The system will try to start 3 times, then give up.

## Tuning & Behavior
*   **Recommendation:** Set to **3 or 5** for autonomous missions to ensure a mechanical issue doesn't lead to a total electrical failure.