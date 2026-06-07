---
layout: parameter
name: H_DCP_SCALER
display_name: Dual Cyclic Pitch Scaler
description: Scaling factor for differential cyclic pitch on tandem helicopters (e.g. Chinook).
default_value: 0.25
range: 0 1.0
units: 
group: H
visual_asset_id: heli_swash_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Motors/AP_MotorsHeli_Dual.cpp#L100
---

# Dual Cyclic Pitch Scaler (H_DCP_SCALER)

## Description
`H_DCP_SCALER` is used for Tandem (two-rotor) helicopters like the CH-47 Chinook.

In a tandem helicopter, yaw is controlled by tilting the two swashplates in opposite directions (Differential Cyclic Pitch). This parameter scales that effect.

*   **Tuning:** Adjust so that the yaw response is balanced and does not cause unwanted rolling or pitching.
