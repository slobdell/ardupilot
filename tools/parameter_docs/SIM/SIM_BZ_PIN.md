---
layout: parameter
name: SIM_BZ_PIN
display_name: Simulation Buzzer Pin
description: The GPIO pin number assigned to the simulated buzzer.
default_value: -1
range: -1 100
units: 
group: SIM
visual_asset_id: brd_io_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L156
---

# Simulation Buzzer Pin (SIM_BZ_PIN)

## Description
`SIM_BZ_PIN` tells the simulator which virtual pin is connected to the beeper.
