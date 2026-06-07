---
layout: parameter
name: RCMAP_LATERAL
display_name: Lateral Channel Mapping
description: Selects the RC input channel used for side-to-side (strafing) movement.
default_value: 0
range: 1 16
units: 
group: RCMAP
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_RCMapper/AP_RCMapper.cpp#L61
---

# Lateral Channel Mapping (RCMAP_LATERAL)

## Description
`RCMAP_LATERAL` allows you to customize which stick or switch controls the vehicle's left/right strafing movement.

This is essential for vehicles capable of lateral translation without rolling, such as 6-DOF drones and ROVs.