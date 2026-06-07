---
layout: parameter
name: FS_LONG_ACTN
display_name: Long Failsafe Action (Plane)
description: Defines the action taken when radio control is lost for an extended period.
default_value: 0
range: 0 4
units: 
group: FS
visual_asset_id: failsafe_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduPlane/Parameters.cpp#L468
---

# Long Failsafe Action (FS_LONG_ACTN)

## Description
`FS_LONG_ACTN` defines the "Plan B" for a sustained radio link failure. While [FS_SHORT_ACTN](FS_SHORT_ACTN.html) handles brief glitches, the "Long" action is triggered after the connection has been dead for several seconds (see [FS_LONG_TIMEOUT](FS_LONG_TIMEOUT.html)).

*   **0: Continue (Standard).** If in AUTO mode, the plane keeps flying its mission. If in manual, it triggers RTL.
*   **1: RTL.** The plane returns home immediately regardless of mode.
*   **2: FBWA.** The plane level the wings and holds altitude (Circle mode fallback).
*   **3: Parachute.** Deploys the parachute if configured.

## Tuning & Behavior
*   **Default:** 0.
*   **Safety:** For most users, setting this to **1 (RTL)** is the safest choice to ensure the plane comes back if the radio fails.