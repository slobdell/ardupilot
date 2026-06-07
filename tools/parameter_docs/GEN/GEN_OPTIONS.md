---
layout: parameter
name: GEN_OPTIONS
display_name: Generator Options
description: Bitmask of options for onboard generators.
default_value: 0
range: 
units: 
group: GEN
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Generator/AP_Generator.cpp
---

# Generator Options (GEN_OPTIONS)

## Description
Configuration bitmask for tailoring the generator's interaction with the flight controller.

## Tuning & Behavior
*   **Default Value:** 0
*   **Bitmask:**
    *   Bit 0: Suppress Maintenance-Required Warnings