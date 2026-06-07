---
layout: parameter
name: PUP_PITCH
display_name: "Custom pitch"
description: "Custom orientation pitch angle"
default_value: 0
range: -180 180
units: "deg"
group: PUP
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_CustomRotations/AP_CustomRotations_params.cpp#L21
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Custom pitch (PUP_PITCH)

## Description
This parameter defines the **Pitch** component of a custom user-defined rotation. It is part of the `CUSTOM_ORIENTATION` system, allowing you to define arbitrary sensor mounting angles that do not fit the standard 90-degree increments (e.g., a GPS mounted on a 15-degree slope).

## The Mathematics
The rotation is applied as an intrinsic Euler sequence (Yaw -> Pitch -> Roll).
$$ R_{\text{total}} = R_z(\text{PUP\_YAW}) \cdot R_y(\text{PUP\_PITCH}) \cdot R_x(\text{PUP\_ROLL}) $$

## The Engineer's View
Defined in `libraries/AP_CustomRotations/AP_CustomRotations_params.cpp`.

## Tuning & Behavior
*   **Default Value:** 0 deg
*   **Usage:** Set `AHRS_ORIENTATION` (or sensor specific orientation) to `100` (Custom) to use these values.