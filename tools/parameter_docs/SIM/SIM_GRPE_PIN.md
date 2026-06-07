---
layout: parameter
name: SIM_GRPE_PIN
display_name: Simulated EPM Gripper Pin
description: The servo output channel assigned to control the simulated EPM gripper.
default_value: 0
range: 1 32
units: 
group: SIM
visual_asset_id: gripper_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SIM_Gripper_EPM.cpp#L25
---

# Simulated EPM Gripper Pin (SIM_GRPE_PIN)

## Description
`SIM_GRPE_PIN` links the virtual EPM magnet to an output channel.