---
layout: parameter
name: EFI_OFS
display_name: EFI Throttle Linearization Offset
description: The baseline offset for the throttle linearization curve.
default_value: 0
range: 0 1.0
units: 
group: EFI
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_EFI/AP_EFI_ThrottleLinearisation.cpp#L32
---

# EFI Throttle Linearization Offset (EFI_OFS)

## Description
`EFI_OFS` defines the starting point of the power curve calibration.