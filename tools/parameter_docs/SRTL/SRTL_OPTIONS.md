---
layout: parameter
name: SRTL_OPTIONS
display_name: "SmartRTL options"
description: "Bitmask of advanced SmartRTL behaviors"
default_value: 0
range: 0 3
units: "Bitmask"
group: SRTL
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_SmartRTL/AP_SmartRTL.cpp#L44
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_SmartRTL/AP_SmartRTL.h#L186
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# SmartRTL options (SRTL_OPTIONS)

## Description
This bitmask allows you to customize the behavior of the Smart RTL (Return To Launch) mode, which returns the vehicle home by retracing its outbound path.

## The Mathematics
Bitmask.

## The Engineer's View
Defined in `libraries/AP_SmartRTL/AP_SmartRTL.cpp`.
*   **Bit 0:** Ignore Pilot Yaw. If set, the vehicle will face the direction of travel along the path rather than allowing the pilot to look around.
*   **Bit 1:** Prune Path. If set, the algorithm aggressively simplifies the path to save memory.

## Tuning & Behavior
*   **Default Value:** 0
*   **Recommendation:** Default is usually best.