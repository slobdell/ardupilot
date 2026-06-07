---
layout: parameter
name: SIM_SPEEDUP
display_name: Simulation Speedup
description: The speedup factor for the simulation relative to real-time.
default_value: -1
range: -1 100
units: 
group: SIM
visual_asset_id: sim_speedup_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L200
---

# Simulation Speedup (SIM_SPEEDUP)

## Description
`SIM_SPEEDUP` allows you to run the simulation faster than real-time.

*   **1:** Real-time (1 second = 1 second).
*   **10:** 10x speed. Useful for flying long missions quickly.
*   **-1 (Default):** Run as fast as the computer CPU allows.

## Tuning & Behavior
*   **Default Value:** -1.
*   **Note:** If your computer is slow, the simulation might run *slower* than real-time even if you set this to 10.
