---
layout: parameter
name: RALLY_LIMIT_KM
display_name: "Rally Limit"
description: "Maximum allowable distance to a Rally Point"
default_value: 5
range: 0 100
units: "km"
group: RALLY
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Rally/AP_Rally.cpp#L42
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Rally/AP_Rally.h#L73
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Rally Limit (RALLY_LIMIT_KM)

## Description
This is a safety parameter ("Sanity Check") for Rally Points. If the nearest Rally Point is further away than this limit, the autopilot will ignore it and default to returning to Home (RTL) instead. This prevents the dangerous situation where a drone tries to fly to a Rally Point saved from a previous mission at a distant location (e.g., a different flying field).

## The Mathematics
Logic Check:
$$ 	ext{Target} = \begin{cases} 	ext{Rally Point} & \text{if } 	ext{Dist}(	ext{Vehicle}, 	ext{Rally}) < 	ext{RALLY_LIMIT_KM} \ 	ext{Home} & \text{otherwise} \end{cases} $$

## The Engineer's View
Defined in `libraries/AP_Rally/AP_Rally.cpp`.
*   **0:** Disabled. The closest rally point is ALWAYS used, regardless of distance.
*   **>0:** Enforces the distance limit.

## Tuning & Behavior
*   **Default Value:** 5 km
*   **Recommendation:** Keep this set to a reasonable radius for your operation (e.g., 2-5km) to prevent fly-aways.