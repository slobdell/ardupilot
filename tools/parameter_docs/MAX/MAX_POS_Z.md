---
layout: parameter
name: MAX_POS_Z
display_name: Max Vertical Position Delta (Blimp)
description: Sets the maximum allowed vertical position change per update cycle.
default_value: 0.2
range: 0.1 5.0
units: m/s
group: MAX
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/Blimp/Parameters.cpp#L243
---

# Max Vertical Position Delta (MAX_POS_Z)

## Description
`MAX_POS_Z` limits how fast the vertical target position can move in **ArduBlimp**. It ensures that altitude changes are smooth and don't overwhelm the blimp's limited vertical thrust.