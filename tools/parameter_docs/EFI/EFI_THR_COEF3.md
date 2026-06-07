---
layout: parameter
name: EFI_THR_COEF3
display_name: Throttle linearisation - Third Order
description: Third Order Polynomial Coefficient for EFI throttle linearisation.
default_value: 0
range: -1 1
units: 
group: EFI
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_EFI/AP_EFI_ThrottleLinearisation.cpp
---

# Throttle linearisation - Third Order (EFI_THR_COEF3)

## Description
Cubic term for the EFI throttle linearization polynomial.