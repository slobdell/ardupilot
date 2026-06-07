---
layout: parameter
name: SAIL_ANGLE_IDEAL
display_name: "Sail ideal angle"
description: "Ideal angle of attack between sail and apparent wind"
default_value: 25
range: 0 90
units: "deg"
group: SAIL
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/Rover/sailboat.cpp#L58
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/Rover/sailboat.h#L104
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Sail ideal angle (SAIL_ANGLE_IDEAL)

## Description
This parameter defines the optimal angle of attack for the mainsail to generate maximum thrust. The autopilot uses this value, combined with the wind vane reading (apparent wind direction), to automatically trim the sail servo.

## The Mathematics
$$ \theta_{\text{sail}} = \theta_{\text{wind}} - \text{SAIL\_ANGLE\_IDEAL} $$
(Simplified logic for sail setting).

## The Engineer's View
Defined in `Rover/sailboat.cpp`. Used in the `update_mainsail()` function.
*   **Physics:** Represents the angle where the lift/drag ratio of the sail is maximized.

## Tuning & Behavior
*   **Default Value:** 25 deg
*   **Adjustment:**
    *   **Soft Sails:** Typically 20-30 degrees.
    *   **Wing Sails:** May require different settings based on the airfoil profile.