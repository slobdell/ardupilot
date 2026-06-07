---
layout: parameter
name: FOLL_OPTIONS
display_name: "Follow options"
description: "Bitmask for configuring advanced Follow mode behaviors."
default_value: 0
range: null
units: "Bitmask"
group: FOLL
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Follow/AP_Follow.cpp#L142
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Follow options (FOLL_OPTIONS)

## Description
This parameter allows the user to enable specialized behaviors for Follow mode via a bitmask. Currently, it primarily controls how camera gimbals interact with the target tracking system.

## The Mathematics
The parameter is a bitmask ($B$):

*   **Bit 0 (Value 1): Mount Follows lead vehicle on mode enter.**
    When this bit is set and the vehicle enters Follow mode, the autopilot will automatically command any connected gimbal (Mount) to point at the Lead Vehicle's calculated position.

## The Engineer's View
In `AP_Follow` (and consumed by vehicle-specific code like `mode_follow.cpp`), this parameter maps to `_options`.
*   **Mount Tracking:** If Bit 0 is set, the Follow library or the main vehicle code will set the Gimbal's Region of Interest (ROI) to the target's coordinates. This creates a "Cinematic Follow" effect where the drone chases the target while keeping it centered in the camera frame, regardless of the drone's actual orientation.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled).
*   **Bit 0 (1):** Enable this for filming applications. Note that this overrides manual gimbal control while in Follow mode.

