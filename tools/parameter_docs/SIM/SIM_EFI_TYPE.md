---
layout: parameter
name: SIM_EFI_TYPE
display_name: Simulated EFI Type
description: Selects the type of Electronic Fuel Injection (EFI) system to simulate.
default_value: 0
range: 0 8
units: 
group: SIM
visual_asset_id: sim_efi_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated EFI Type (SIM_EFI_TYPE)

## Description
`SIM_EFI_TYPE` adds a virtual engine to the simulation.

*   **0:** Disabled.
*   **1:** MegaSquirt.
*   **2:** Loweheiser.
*   **8:** Hirth.

## Tuning & Behavior
*   **Default Value:** 0.
*   **Usage:** Enable this to test your `EFI_*` parameter configuration and OSD layout.