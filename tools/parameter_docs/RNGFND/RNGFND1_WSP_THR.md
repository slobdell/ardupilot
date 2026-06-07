---
layout: parameter
name: RNGFND1_WSP_THR
display_name: Wasp-LRF Sensitivity Threshold
description: Sets the system sensitivity for the laser receiver.
default_value: -1
range: -1 255
units: 
group: RNGFND
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_RangeFinder/AP_RangeFinder_Wasp.cpp#L59
---

# Wasp-LRF Sensitivity Threshold (RNGFND1_WSP_THR)

## Description
`RNGFND1_WSP_THR` controls the "Gain" of the laser receiver.

*   **Higher Value:** Higher sensitivity. Can see farther or over darker surfaces, but more prone to false readings from fog or dust.
*   **-1:** Automatic threshold adjustment.