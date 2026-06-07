---
layout: parameter
name: SOAR_POLAR_B
display_name: Induced Drag Coefficient
description: The coefficient representing drag created by the production of lift (induced drag).
default_value: 0.031
range: 0.005 0.05
units: 
group: SOAR
visual_asset_id: glider_polar_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Soaring/AP_Soaring.cpp#L85
---

# Induced Drag Coefficient (SOAR_POLAR_B)

## Description
`SOAR_POLAR_B` describes how much speed the glider loses when it pulls up or turns.

As an aircraft produces more lift (e.g., during a turn), it creates "Induced Drag." This parameter tells the soaring controller how much extra sink rate to expect when the plane is banking in a thermal.

## Tuning & Behavior
*   **Default Value:** 0.031.
*   **Recommendation:** High aspect ratio wings (long, skinny wings) have a lower `B` value (more efficient). Stubby wings have a higher `B`.