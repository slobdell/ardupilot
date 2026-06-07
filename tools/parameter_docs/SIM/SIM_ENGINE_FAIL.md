---
layout: parameter
name: SIM_ENGINE_FAIL
display_name: Simulated Engine Failure
description: The motor index (0-based) to apply the failure multiplier to.
default_value: -1
range: -1 8
units: 
group: SIM
visual_asset_id: sim_failure_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated Engine Failure (SIM_ENGINE_FAIL)

## Description
`SIM_ENGINE_FAIL` selects the victim motor for failure testing.

*   **-1 (Default):** No failure.
*   **0:** Motor 1 fails.
*   **1:** Motor 2 fails.

## Tuning & Behavior
*   **Default Value:** -1.
*   **Procedure:**
    1.  Take off and hover.
    2.  Set `SIM_ENGINE_MUL` to 0.
    3.  Set `SIM_ENGINE_FAIL` to 0 (Motor 1).
    4.  Observe if the drone crashes or spins.