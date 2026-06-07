---
layout: parameter
name: PTCH_TRIM_DEG
display_name: "Pitch angle offset"
description: "Pitch angle trim for level flight"
default_value: 0.0f
range: -45 45
units: "deg"
group: PTCH
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/Parameters.cpp#L675
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Pitch angle offset (PTCH_TRIM_DEG)

## Description
This parameter trims the aircraft's pitch attitude definition of "Level Flight". If your plane flies level but the HUD shows it is pitched up (or down), you can adjust this parameter to align the autopilot's horizon with reality. It effectively rotates the AHRS solution.

## The Mathematics
$$ \theta_{\text{nav}} = \theta_{\text{imu}} - \text{PTCH_TRIM_DEG} $$

## The Engineer's View
Defined in `ArduPlane/Parameters.cpp`.
*   **Usage:** Alternative to performing a "Level Horizon" calibration on the bench. Useful for tuning in the field.

## Tuning & Behavior
*   **Default Value:** 0.0 deg
*   **Adjustment:** If the plane loses altitude in "Level" flight modes (FBWA), increase this value (pitch up).