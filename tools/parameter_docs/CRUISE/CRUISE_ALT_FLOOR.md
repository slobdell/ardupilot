---
layout: parameter
name: CRUISE_ALT_FLOOR
display_name: "Minimum altitude for FBWB and CRUISE mode"
description: "Hard altitude floor for assisted flight modes"
default_value: 0
range: 0 100
units: "m"
group: CRUISE
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/Parameters.cpp#L689
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Minimum altitude for FBWB and CRUISE mode (CRUISE_ALT_FLOOR)

## Description
This parameter creates a virtual "floor" or minimum altitude for the FBWB and CRUISE flight modes. If the pilot tries to descend below this altitude (measured above Home), the autopilot will ignore the pitch-down command and level off. This is a safety feature to prevent low-level crashes during long-range cruising.

## The Mathematics
$$ \text{Pitch Target} = \text{Constrain}(\text{Pilot Input}) \text{ s.t. } \text{Alt} \ge \text{CRUISE_ALT_FLOOR} $$

## The Engineer's View
Defined in `ArduPlane/Parameters.cpp`.
*   **0:** Disabled.
*   **>0:** Minimum altitude in meters.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled)
*   **Safety:** Setting this to e.g., 50m ensures you never accidentally fly into terrain while cruising.