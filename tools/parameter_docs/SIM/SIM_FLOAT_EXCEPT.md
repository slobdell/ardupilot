---
layout: parameter
name: SIM_FLOAT_EXCEPT
display_name: Simulated Floating Point Exceptions
description: Enables crashing the simulator if a floating-point error (NaN/Infinity) is detected.
default_value: 1
range: 0 1
units: 
group: SIM
visual_asset_id: sim_physics_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated Floating Point Exceptions (SIM_FLOAT_EXCEPT)

## Description
`SIM_FLOAT_EXCEPT` is a developer safety tool.

If enabled, the simulator will immediately "Hard Crash" if any part of the code performs an illegal math operation (like dividing by zero or taking the square root of a negative number). This is vital for catching bugs before they are ever flown on real hardware.

## Tuning & Behavior
*   **Default Value:** 1 (Enabled).
*   **Recommendation:** Keep at **1** at all times unless you are debugging a known math issue that you need the simulator to bypass.