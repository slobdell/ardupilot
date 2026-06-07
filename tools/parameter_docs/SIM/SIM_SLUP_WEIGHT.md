---
layout: parameter
name: SIM_SLUP_WEIGHT
display_name: Slung Payload Weight
description: The weight (mass) of the simulated slung payload in kilograms.
default_value: 1.0
range: 0 15
units: kg
group: SIM
visual_asset_id: sim_physics_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SIM_SlungPayload.cpp#L41
---

# Slung Payload Weight (SIM_SLUP_WEIGHT)

## Description
`SIM_SLUP_WEIGHT` sets the mass of the underslung object.

## Tuning & Behavior
*   **Default Value:** 1.0 kg.
*   **Effect:** Increasing the weight increases the "Pendulum Effect." A heavy payload can pull the drone into a state where it can no longer maintain attitude or altitude if it starts swinging excessively.