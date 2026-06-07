---
layout: parameter
name: RTL_AUTOLAND
display_name: "RTL auto land"
description: "Automatically begin landing sequence after arriving at RTL location."
default_value: 0
range: 0 3
units: ""
group: RTL
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/Parameters.cpp#L742
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# RTL auto land (RTL_AUTOLAND)

## Description
This parameter controls the behavior of the aircraft when it reaches the Return-To-Launch (RTL) destination. Instead of simply loitering at the home or rally point, the aircraft can be configured to automatically initiate a landing sequence. This feature allows for fully autonomous recovery missions but requires careful setup of `DO_LAND_START` mission items to define the approach path.

## The Mathematics
The parameter acts as a state machine configuration for the RTL flight mode controller.

$$ \text{Behavior} = \begin{cases} \text{Loiter at Home} & \text{if } \text{RTL\_AUTOLAND} = 0 \\ \text{Land (Rally)} & \text{if } \text{RTL\_AUTOLAND} = 1 \\ \text{Land (Home)} & \text{if } \text{RTL\_AUTOLAND} = 2 \\ \text{Loiter (No Check)} & \text{if } \text{RTL\_AUTOLAND} = 3 \end{cases} $$

## The Engineer's View
Defined in `ArduPlane/Parameters.cpp`. The values correspond to the `RtlAutoland` enum:
*   `RTL_DISABLE` (0): Standard RTL behavior (loiter over Home/Rally).
*   `RTL_RALLY` (1): Land at the nearest Rally point if defined and in range.
*   `RTL_HOME` (2): Land at the Home position.
*   `RTL_DISABLE_WO_CHECK` (3): Do not land, and suppress the pre-arm check that normally requires a `DO_LAND_START` item if `RTL_AUTOLAND` is active.

## Tuning & Behavior
*   **0 (Disabled):** The aircraft will return to home (or rally point) and loiter indefinitely until the battery fails or manual control is taken.
*   **1 (Rally):** Initiates landing at the nearest valid Rally Point.
*   **2 (Home):** Initiates landing at Home.
*   **3 (Disable w/o Check):** Useful for using `DO_LAND_START` as a pure "Go Around" or "Abort" waypoint without forcing an automatic landing at the end of an RTL.