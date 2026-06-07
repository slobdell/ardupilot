---
layout: parameter
name: AFS_QNH_PRESSURE
display_name: QNH pressure
description: This sets the QNH pressure in millibars to be used for pressure altitude in the altitude limit. A value of zero disables the altitude limit.
default_value: 0
range: 
units: hPa
group: AFS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_AdvancedFailsafe/AP_AdvancedFailsafe.cpp
---

# QNH pressure (AFS_QNH_PRESSURE)

## Description
Reference sea-level pressure for barometric altitude limit calculation.

## Tuning & Behavior
*   **Default Value:** 0 hPa (Disabled)
*   **Must be set correctly for AMSL limiting to be accurate.**
