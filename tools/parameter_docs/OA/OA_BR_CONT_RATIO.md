---
layout: parameter
name: OA_BR_CONT_RATIO
display_name: BendyRuler Continuity Ratio
description: Determines how much better an alternative path must be before the drone switches to it.
default_value: 1.5
range: 1.0 5.0
units: 
group: OA
visual_asset_id: avoid_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_Avoidance/AP_OABendyRuler.cpp#L101
---

# BendyRuler Continuity Ratio (OA_BR_CONT_RATIO)

## Description
`OA_BR_CONT_RATIO` prevents the drone from "Indecisive" maneuvering.

When the BendyRuler algorithm finds an alternative path around an obstacle, it compares the "Clearance" (margin) of the new path to the current one. This parameter defines the required improvement. If set to 1.5, the new path must have 50% more clearance than the current path before the drone will turn toward it. This prevents the drone from constantly twitching back and forth between two similar-looking gaps.