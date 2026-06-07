---
layout: parameter
name: H_SW2_H3_ENABLE
display_name: Swashplate 2 Type
description: Enables and selects the geometry for the second rotor's swashplate (Dual Heli only).
default_value: 0
range: 0 1
units: 
group: H
visual_asset_id: heli_dual_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Motors/AP_MotorsHeli_Dual.cpp#L25
---

# Swashplate 2 Type (H_SW2_H3_ENABLE)

## Description
`H_SW2_H3_ENABLE` configures the physical servo layout for the second rotor on a Dual-Rotor helicopter (Tandem, Coaxial, or Intermeshing).

*   **0:** Non-CCPM (Standard separate servos).
*   **1:** H3-120 (3 servos arranged at 120-degree intervals).

## Tuning & Behavior
*   **Default Value:** 0.
*   **Recommendation:** Match the physical layout of your second swashplate.