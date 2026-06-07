---
layout: parameter
name: SIM_SHOVE_Z
display_name: Simulation Shove Z
description: Applies a vertical force (in m/s/s) to the vehicle to simulate a downward or upward push.
default_value: 0
range: -100 100
units: m/s/s
group: SIM
visual_asset_id: physics_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L236
---

# Simulation Shove Z (SIM_SHOVE_Z)

## Description
`SIM_SHOVE_Z` simulates a sudden vertical impact or force.

*   **Positive Value:** Pushes the drone **Down**.
*   **Negative Value:** Pushes the drone **Up**.

## Tuning & Behavior
*   **Testing:** Set to **20** for a fraction of a second to simulate a heavy object being dropped on the drone or a sudden downburst. Test the position controller's ability to recover the target altitude.
