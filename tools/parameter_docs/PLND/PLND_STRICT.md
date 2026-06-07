---
layout: parameter
name: PLND_STRICT
display_name: Precision Landing Strictness
description: Determines how the autopilot reacts if the landing target is lost during the approach.
default_value: 1
range: 0 2
units: 
group: PLND
visual_asset_id: precland_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PrecLand/AC_PrecLand.cpp#L106
---

# Precision Landing Strictness (PLND_STRICT)

## Description
`PLND_STRICT` decides the "Plan B" if the drone loses sight of its landing target.

Sometimes the target is obscured by grass, glare, or a temporary sensor glitch. 

*   **0: Land Vertically (Not strict).** If the target is lost, the drone just lands wherever it is.
*   **1: Retry Landing (Normal).** If the target is lost, the drone will stop descending, potentially climb back up, and try to re-acquire the target.
*   **2: Just Hover (Very Strict).** The drone will never land unless it can see the target. If the target is lost, it will hover indefinitely (or until failsafe triggers).

## Tuning & Behavior
*   **Default Value:** 1.
*   **Recommendation:** Use **1** for most autonomous missions. Use **2** for high-value payloads where landing on bare earth (instead of the pad) is unacceptable.