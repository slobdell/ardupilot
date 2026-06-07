---
layout: parameter
name: SIM_SLUP_LINELEN
display_name: Slung Payload Line Length
description: The length of the tether (in meters) from the drone to the slung payload.
default_value: 30.0
range: 1 100
units: m
group: SIM
visual_asset_id: sim_physics_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SIM_SlungPayload.cpp#L49
---

# Slung Payload Line Length (SIM_SLUP_LINELEN)

## Description
`SIM_SLUP_LINELEN` sets the distance between the drone and the payload.

## Tuning & Behavior
*   **Default Value:** 30 m.
*   **Effect:** Longer lines result in slower pendulum oscillations but can lead to very large displacements. Shorter lines react much more quickly and can impart sharp "Jerk" forces to the flight controller.