---
layout: parameter
name: EFI_THR_COEF2
display_name: Throttle linearisation - Second Order
description: Second Order Polynomial Coefficient for EFI throttle linearisation.
default_value: 0
range: -1 1
units: 
group: EFI
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_EFI/AP_EFI_ThrottleLinearisation.cpp
---

# Throttle linearisation - Second Order (EFI_THR_COEF2)

## Description
Quadratic term for the EFI throttle linearization polynomial.