---
layout: parameter
name: SIM_THML_SCENARI
display_name: Simulation Thermal Scenarios
description: Selects pre-defined weather and lift scenarios for autonomous soaring (ArduSoar) testing.
default_value: 0
range: 0 5
units: 
group: SIM
visual_asset_id: soaring_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L513
---

# Simulation Thermal Scenarios (SIM_THML_SCENARI)

## Description
`SIM_THML_SCENARI` defines the "Thermal Map" for autonomous glider testing.

Instead of just one random thermal, this parameter selects different distributions of rising air. Useful for verifying that ArduSoar can reliably find and track lift in varied atmospheric conditions.