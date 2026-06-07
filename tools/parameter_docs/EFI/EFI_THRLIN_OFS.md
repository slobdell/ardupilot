---
layout: parameter
name: EFI_THRLIN_OFS
display_name: throttle linearization offset
description: Offset for throttle linearization.
default_value: 0
range: 0 100
units: 
group: EFI
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_EFI/AP_EFI_ThrottleLinearisation.cpp
---

# throttle linearization offset (EFI_THRLIN_OFS)

## Description
Constant offset added to the linearized throttle output.