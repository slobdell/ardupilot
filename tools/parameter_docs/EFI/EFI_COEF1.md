---
layout: parameter
name: EFI_COEF1
display_name: EFI Calibration Coefficient 1
description: Used to calibrate fuel flow for MS protocol (Slope).
default_value: 0
range: 0 1
units: 
group: EFI
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_EFI/AP_EFI.cpp
---

# EFI Calibration Coefficient 1 (EFI_COEF1)

## Description
Scaling factor (slope) for fuel flow calculation when using the MegaSquirt (MS) EFI protocol.