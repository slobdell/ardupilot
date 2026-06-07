---
layout: parameter
name: SIM_SLUP_DRAG
display_name: Slung Payload Drag Coefficient
description: The drag coefficient of the slung payload (higher values increase air resistance).
default_value: 1.0
range: 0 10
units: 
group: SIM
visual_asset_id: sim_physics_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SIM_SlungPayload.cpp#L57
---

# Slung Payload Drag Coefficient (SIM_SLUP_DRAG)

## Description
`SIM_SLUP_DRAG` determines how "Aerodynamic" the payload is.

A high drag coefficient (e.g. 5.0) simulates a bulky object (like a large box) that will be pushed backward by the wind as the drone flies forward. A low value (e.g. 0.1) simulates a streamlined weight that hangs mostly vertical even at high speeds.

## Tuning & Behavior
*   **Default Value:** 1.0.