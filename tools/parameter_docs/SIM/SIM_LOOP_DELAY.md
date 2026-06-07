---
layout: parameter
name: SIM_LOOP_DELAY
display_name: Simulated Loop Delay
description: A constant delay (in milliseconds) added to each simulator update.
default_value: 0
range: 0 100
units: ms
group: SIM
visual_asset_id: sim_physics_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated Loop Delay (SIM_LOOP_DELAY)

## Description
`SIM_LOOP_DELAY` simulates a "Slow Processor."

If you set this to 5ms, every single logic loop in the autopilot will take 5ms longer than usual. This is a great way to test the safety margins of your loop rate and see at what point the drone becomes unflyable due to latency.