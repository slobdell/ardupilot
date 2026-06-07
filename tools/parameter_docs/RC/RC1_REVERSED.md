---
layout: parameter
name: RC1_REVERSED
display_name: RC Input Channel 1 Reversal
description: Reverses the interpretation of the stick input for Channel 1.
default_value: 0
range: 0 1
units: 
group: RC
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/RC_Channel/RC_Channel.cpp#L100
---

# RC Input Channel 1 Reversal (RC1_REVERSED)

## Description
`RC1_REVERSED` flips the logic of your stick. If you push the stick right but the GCS shows the bar moving left, you set this to 1. 

*Note: It is always preferred to fix this during Radio Calibration in the GCS.*