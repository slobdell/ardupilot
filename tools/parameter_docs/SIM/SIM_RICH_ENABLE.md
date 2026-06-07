---
layout: parameter
name: SIM_RICH_ENABLE
display_name: Simulated Rich Environment Enable
description: Enables the "Rich" simulation model (advanced error injection and environmental factors).
default_value: 0
range: 0 1
units: 
group: SIM
visual_asset_id: sim_physics_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated Rich Environment Enable (SIM_RICH_ENABLE)

## Description
`SIM_RICH_ENABLE` turns on the "Chaos Monkey."

It enables a suite of randomized sensor glitches, timing jitters, and environmental disturbances designed to stress-test the autopilot's failsafe logic. It is primarily used by developers to find bugs in error handling code.

## Tuning & Behavior
*   **0:** Disabled.
*   **1:** Enabled.