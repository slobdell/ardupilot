---
layout: parameter
name: FILT1_NOTCH_Q
display_name: Notch Filter Quality Factor (Q)
description: Defines the "Width" or sharpness of the notch filter.
default_value: 1.0
range: 0.1 5.0
units: 
group: FILT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/Filter/AP_NotchFilter_params.cpp#L24
---

# Notch Filter Quality Factor (FILT1_NOTCH_Q)

## Description
`FILT1_NOTCH_Q` determines how narrow the "Notch" is.

*   **Higher Q (e.g. 2.0):** Narrow notch. Removes a very specific frequency without affecting nearby data.
*   **Lower Q (e.g. 0.5):** Wide notch. Removes a broader range of frequencies around the center.