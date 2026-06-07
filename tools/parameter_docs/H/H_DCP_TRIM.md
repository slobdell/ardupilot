---
layout: parameter
name: H_DCP_TRIM
display_name: Direct Cyclic Pitch Trim
description: A trim offset added to the direct cyclic pitch input.
default_value: 0
range: -0.1 0.1
units: 
group: H
visual_asset_id: heli_swash_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Motors/AP_MotorsHeli_Single.cpp#L100
---

# Direct Cyclic Pitch Trim (H_DCP_TRIM)

## Description
`H_DCP_TRIM` provides a static offset to the cyclic pitch.