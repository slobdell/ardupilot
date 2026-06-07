---
layout: parameter
name: DEV_OPTIONS
display_name: Development options
description: Bitmask of developer options. The meanings of the bit fields in this parameter may vary at any time.
default_value: 0
range: 
units: 
group: DEV
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduCopter/Parameters.cpp
---

# Development options (DEV_OPTIONS)

## Description
A bitmask for enabling experimental or development-only features. These options are typically used by ArduPilot developers and may change without notice.

## Tuning & Behavior
*   **Default Value:** 0
*   **Bitmask Examples (Copter):**
    *   Bit 0: ADSBMavlinkProcessing
    *   Bit 1: DevOptionVFR_HUDRelativeAlt