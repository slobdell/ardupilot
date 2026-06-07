---
layout: parameter
name: ACT_VLT_OFFSET
display_name: Volage offset
description: Voltage offset on voltage pin. This allows for an offset due to a diode. This voltage is subtracted before the scaling is applied.
default_value: 0
range: 
units: V
group: ACT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_BattMonitor/AP_BattMonitor_AD7091R5.cpp
---

# Volage offset (ACT_VLT_OFFSET)

## Description
Voltage offset on voltage pin. This allows for an offset due to a diode. This voltage is subtracted before the scaling is applied.

## Tuning & Behavior
*   **Default Value:** 0 V
