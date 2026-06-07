---
layout: parameter
name: DISTANCE_MIN
display_name: "Distance minimum to target"
description: "Minimum distance for active tracking"
default_value: 0
range: 0 100
units: "m"
group: Uncategorized
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/AntennaTracker/Parameters.cpp#L175
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Distance minimum to target (DISTANCE_MIN)

## Description
This parameter defines a "Cone of Silence" radius around the Antenna Tracker. If the target vehicle comes closer than this distance, the tracker stops updating its pan/tilt angles and holds position. This prevents the tracker from whipping around violently or grinding its gears trying to track a target passing directly overhead or nearby.

## The Mathematics
$$ \text{If } \text{Distance} < \text{DISTANCE_MIN} \implies \text{Hold Position} $$

## The Engineer's View
Defined in `AntennaTracker/Parameters.cpp`.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled)
*   **Recommendation:** Set to 5-10 meters to protect the mechanism during launch/landing near the tracker.