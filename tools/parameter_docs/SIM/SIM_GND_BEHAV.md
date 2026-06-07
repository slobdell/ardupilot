---
layout: parameter
name: SIM_GND_BEHAV
display_name: Simulated Ground Behavior
description: Selects the physics model for ground interaction (Standard, Tailsitter, etc.).
default_value: -1
range: -1 2
units: 
group: SIM
visual_asset_id: sim_physics_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated Ground Behavior (SIM_GND_BEHAV)

## Description
`SIM_GND_BEHAV` modifies how the drone interacts with the virtual earth.

*   **-1:** Automatic (standard).
*   **0:** Non-Tailsitter (stays flat).
*   **1:** Tailsitter (leans back onto its tail).
*   **2:** Stay on ground (locked position).

## Tuning & Behavior
*   **Default Value:** -1.
*   **Recommendation:** Leave at **-1** unless you are testing a tailsitter QuadPlane.