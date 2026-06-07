---
layout: parameter
name: H_RSC_AROT_ENBL
display_name: Enable Autorotation Handling
description: Enables the automated autorotation and bailout logic within the Rotor Speed Controller (RSC).
default_value: 0
range: 0 1
units: 
group: H
visual_asset_id: heli_rsc_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_Autorotation/RSC_Autorotation.cpp#L19
---

# Enable Autorotation Handling (H_RSC_AROT_ENBL)

## Description
`H_RSC_AROT_ENBL` activates specialized logic for "Dead-Stick" landings on helicopters.

Autorotation is a maneuver where the main rotor is driven by the upward flow of air during a descent, allowing the helicopter to land safely even if the motor fails. This parameter enables the autopilot to recognize an autorotation state and correctly manage the transition back to powered flight (Bailout) if the engine is restarted in mid-air.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled).
*   **Recommendation:** Enable this if you practice autorotations or have a high-value helicopter where a mid-air motor restart is possible.
