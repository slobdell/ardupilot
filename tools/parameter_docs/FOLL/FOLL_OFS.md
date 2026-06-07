---
layout: parameter
name: FOLL_OFS
display_name: "Follow offsets (Vector)"
description: "Follow offsets in meters (X: North/Forward, Y: East/Right, Z: Down)"
default_value: 0
range: -100 100
units: "m"
group: FOLL
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Follow/AP_Follow.cpp#L109
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Follow/AP_Follow.h#L151
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Follow offsets (FOLL_OFS)

## Description
This vector parameter defines the positional offset of the follower vehicle relative to the lead vehicle. It allows the follower to maintain a specific formation (e.g., flying 5 meters behind and 2 meters above the leader).

## The Mathematics
The offsets are applied in the NED (North-East-Down) or Forward-Right-Down frame, depending on `FOLL_OFS_TYPE`.
$$ \vec{P}_{target} = \vec{P}_{lead} + \begin{bmatrix} \text{FOLL_OFS_X} \\ \text{FOLL_OFS_Y} \\ \text{FOLL_OFS_Z} \end{bmatrix} $$

## The Engineer's View
Defined in `libraries/AP_Follow/AP_Follow.cpp` as a `Vector3f` parameter `_offset`. This creates three sub-parameters in the GCS: `FOLL_OFS_X`, `FOLL_OFS_Y`, and `FOLL_OFS_Z`.
*   **X:** Forward/North offset.
*   **Y:** Right/East offset.
*   **Z:** Down offset (Positive = Below, Negative = Above).

## Tuning & Behavior
*   **FOLL_OFS_X:** +ve is ahead, -ve is behind.
*   **FOLL_OFS_Y:** +ve is right, -ve is left.
*   **FOLL_OFS_Z:** +ve is below, -ve is above.