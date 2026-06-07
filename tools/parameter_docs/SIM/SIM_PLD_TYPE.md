---
layout: parameter
name: SIM_PLD_TYPE
display_name: Simulated Precision Landing Type
description: Selects the sensor type for simulated Precision Landing (IR-Lock, MAVLink, etc.).
default_value: 0
range: 0 5
units: 
group: SIM
visual_asset_id: plnd_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SIM_Precland.cpp#L25
---

# Simulated Precision Landing Type (SIM_PLD_TYPE)

## Description
`SIM_PLD_TYPE` selects the protocol the virtual landing sensor uses.

*   **1:** IR-Lock.
*   **3:** MAVLink (for GCS-based landing targets).

## Tuning & Behavior
*   **Default Value:** 0.
*   **Recommendation:** Use **1 (IR-Lock)** for most autonomous landing tests.