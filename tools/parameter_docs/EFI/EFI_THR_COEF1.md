---
layout: parameter
name: EFI_THR_COEF1
display_name: Throttle linearisation - First Order
description: First Order Polynomial Coefficient for EFI throttle linearisation.
default_value: 1
range: -1 1
units: 
group: EFI
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_EFI/AP_EFI_ThrottleLinearisation.cpp
---

# Throttle linearisation - First Order (EFI_THR_COEF1)

## Description
Primary linear scaling coefficient for the EFI throttle linearization polynomial.