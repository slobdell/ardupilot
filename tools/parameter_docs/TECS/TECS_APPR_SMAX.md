---
layout: parameter
name: TECS_APPR_SMAX
display_name: "Sink rate max for landing approach stage"
description: "Maximum sink rate during landing approach"
default_value: 0
range: 0.0 20.0
units: "m/s"
group: TECS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_TECS/AP_TECS.cpp#L196
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_TECS/AP_TECS.h#L208
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Sink rate max for landing approach stage (TECS_APPR_SMAX)

## Description
This parameter allows for a steeper maximum descent rate specifically during the auto-landing approach phase, overriding the general `TECS_SINK_MAX` limit. This is useful for aircraft that need to descend rapidly to clear obstacles before the runway threshold.

## The Mathematics
$$ \dot{h}_{\text{max}} = (\text{Land Approach}) ? \text{TECS\_APPR\_SMAX} : \text{TECS\_SINK\_MAX} $$

## The Engineer's View
Defined in `libraries/AP_TECS/AP_TECS.cpp`.
*   **0:** Disabled. Uses `TECS_SINK_MAX` for all flight phases.
*   **>0:** Sets the limit in m/s.

## Tuning & Behavior
*   **Default Value:** 0
*   **Warning:** Ensure your airframe can handle the airspeed buildup or has enough drag (flaps/reverse thrust) to descend this fast without overspeeding.