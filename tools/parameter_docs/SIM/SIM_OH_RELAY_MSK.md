---
layout: parameter
name: SIM_OH_RELAY_MSK
display_name: SIM-on-Hardware Relay Mask
description: A bitmask of relays that are passed through to the physical pins when running SITL on hardware.
default_value: 0
range: 0 255
units: 
group: SIM
visual_asset_id: brd_io_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# SIM-on-Hardware Relay Mask (SIM_OH_RELAY_MSK)

## Description
`SIM_OH_RELAY_MSK` enables physical relay pins during "Sim on Hardware."

## Tuning & Behavior
*   **Default Value:** 0.