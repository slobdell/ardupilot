---
layout: parameter
name: GLIDE_SLOPE_THR
display_name: "Glide slope threshold"
description: "Tolerance for re-calculating glide slope"
default_value: 5.0
range: 0 100
units: "m"
group: Uncategorized
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/Parameters.cpp#L107
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Glide slope threshold (GLIDE_SLOPE_THR)

## Description
This parameter sets the "re-calculation threshold" for the auto-takeoff and auto-landing glide slopes. If the aircraft finds itself significantly above the planned path (e.g., due to a thermal or overshoot), rather than diving aggressively to regain the original line, the autopilot will compute a *new*, smoother path from its current location to the target if the error exceeds this threshold.

## The Mathematics
$$ \text{If } (\text{Current Alt} - \text{Path Alt}) > \text{GLIDE\_SLOPE\_THR} \implies \text{Recalculate Slope} $$

## The Engineer's View
Defined in `ArduPlane/Parameters.cpp`.
*   **Benefit:** Prevents "porpoising" or aggressive pitch-down commands during takeoff climb-out or landing approach.

## Tuning & Behavior
*   **Default Value:** 5.0 m
*   **Behavior:** Higher values force the plane to stick closer to the original path; lower values allow it to adapt (shallow out) the path more easily.