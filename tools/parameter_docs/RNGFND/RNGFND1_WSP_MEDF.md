---
layout: parameter
name: RNGFND1_WSP_MEDF
display_name: Wasp-LRF Median Filter
description: The window size for the real-time median filter.
default_value: 4
range: 0 255
units: Samples
group: RNGFND
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_RangeFinder/AP_RangeFinder_Wasp.cpp#L38
---

# Wasp-LRF Median Filter (RNGFND1_WSP_MEDF)

## Description
`RNGFND1_WSP_MEDF` enables a **Median Filter**, which is excellent at removing "Spikes" from the data. 

Unlike a standard average, a median filter picks the middle value in a set. This ensures that a single bad reading (e.g., a laser reflection from a leaf or a piece of dust) doesn't cause the altitude estimate to jump.