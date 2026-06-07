---
layout: parameter
name: H_OFFSET
display_name: Heli Cyclic Offset
description: A static offset added to the cyclic control outputs (Roll/Pitch).
default_value: 0
range: -0.1 0.1
units: 
group: H
visual_asset_id: heli_swash_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Motors/AP_MotorsHeli_Single.cpp#L100
---

# Heli Cyclic Offset (H_OFFSET)

## Description
`H_OFFSET` provides a global trim for the swashplate.