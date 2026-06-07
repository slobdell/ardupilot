---
layout: parameter
name: SIM_LED_LAYOUT
display_name: Simulation LED Layout
description: Configures the arrangement of virtual LEDs in the simulation.
default_value: 0
range: 0 10
units: 
group: SIM
visual_asset_id: brd_io_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L510
---

# Simulation LED Layout (SIM_LED_LAYOUT)

## Description
`SIM_LED_LAYOUT` defines the number and position of virtual status LEDs in SITL. This is primarily used for verifying LED driver logic and patterns (like those for the SkyViper or ProfiLED) in a simulated environment.
