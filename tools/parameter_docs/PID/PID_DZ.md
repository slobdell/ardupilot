---
layout: parameter
name: PID_DZ
display_name: "Deadzone for the position PIDs"
description: "Positional deadzone in meters where thrust is zeroed"
default_value: 0
range: 0.1 1
units: "m"
group: Uncategorized
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/Blimp/Parameters.cpp#L273
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Deadzone for the position PIDs (PID_DZ)

## Description
This parameter defines a spherical "Rest Zone" around the target loiter point for the Blimp. If the vehicle is within this distance of the target, the position controller outputs zero thrust. This prevents the blimp from constantly making tiny motor adjustments to correct negligible errors, which saves battery and reduces noise.

## The Mathematics
$$ \text{If } \|\vec{P}_{\text{err}}\| < \text{PID\_DZ} \implies \vec{T}_{\text{cmd}} = 0 $$

## The Engineer's View
Defined in `Blimp/Parameters.cpp`. Affects the output of the Loiter controller.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled)
*   **Large Blimps:** Set to 0.5m or 1.0m to allow for drift without constant actuation.