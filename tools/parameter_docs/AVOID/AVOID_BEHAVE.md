---
layout: parameter
name: AVOID_BEHAVE
display_name: Avoidance behaviour
description: Selects how the drone reacts when an obstacle is detected in its path.
default_value: 0
range: 0 1
units: 
group: AVOID
visual_asset_id: avoid_behave_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_Avoidance/AC_Avoid.cpp#L70
---

# Avoidance behaviour (AVOID_BEHAVE)

## Description
`AVOID_BEHAVE` determines the drone's "Personality" when it sees an object like a wall or a tree.

*   **0: Slide (Default for Copter).** The drone will try to "slip" past the obstacle. If you fly straight at a corner, it will veer slightly to one side to maintain speed while keeping a safe distance (`AVOID_MARGIN`).
*   **1: Stop (Default for Rover).** The drone will simply come to a full stop in front of the obstacle. It will not try to go around it.

## The Mathematics
In **Slide (0)** mode, the velocity vector $\vec{V}$ is projected onto the tangent of the obstacle boundary:
$$ \vec{V}_{safe} = \vec{V} - (\vec{V} \cdot \hat{n}) \hat{n} $$
where $\hat{n}$ is the normal vector pointing from the obstacle.

In **Stop (1)** mode, the component of velocity toward the obstacle is simply zeroed.

## Tuning & Behavior
*   **Default Value:** 0 (Slide)
*   **Recommendation:**
    *   **Multicopters:** Use **0 (Slide)**. It feels much more natural and prevents the drone from "stuttering" when flying near complex structures.
    *   **Rovers:** Use **1 (Stop)** to prevent the vehicle from accidentally sliding into a ditch while trying to "veer" around a rock.