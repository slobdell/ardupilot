---
layout: parameter
name: LOIT_SPEED_GAIN
display_name: Loiter speed gain
description: Multiplier for the aggressiveness of the position correction in Rover Loiter mode.
default_value: 0.5
range: 0 5
units: 
group: LOIT
visual_asset_id: loiter_gain_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/Rover/Parameters.cpp#L418
---

# Loiter speed gain (LOIT_SPEED_GAIN)

## Description
`LOIT_SPEED_GAIN` is a **Rover-specific** parameter. It acts like a "Volume Knob" for how aggressively the vehicle tries to get back into its loiter circle.

*   **Low Value:** The rover gently rolls back toward the center when it drifts out.
*   **High Value:** The rover snaps back quickly, potentially causing "overshoot" or rapid motor pulsing.

## The Mathematics
This gain $K_{loit}$ scales the desired velocity $v_{des}$ derived from the distance error $e$:
$$ v_{des} = K_{loit} \cdot \sqrt{2 \cdot a \cdot e} $$
*(Following standard ArduPilot square-root controller logic for stopping distance).*

## The Engineer's View
Maps to `g2.loiter_speed_gain` in the Rover codebase.
It allows users to tune the responsiveness of loiter without having to touch the lower-level `ATC_SPEED_P` or `ATC_STR_RAT_P` gains, which affect all modes.

## Tuning & Behavior
*   **Default Value:** 0.5
*   **Recommendation:**
    *   If the rover "oscillates" (driving back and forth over the loiter point), decrease this to **0.2 or 0.3**.
    *   If the rover drifts way too far before reacting, increase this toward **1.0**.