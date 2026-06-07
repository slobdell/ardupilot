---
layout: parameter
name: BRD_OPTIONS
display_name: Board options
description: Board specific option flags.
default_value: 0
range: 
units: 
group: BRD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_BoardConfig/AP_BoardConfig.cpp
---

# Board options (BRD_OPTIONS)

## Description
Bitmask for low-level hardware configuration options and developer features.

## Tuning & Behavior
*   **Default Value:** 0 (Standard)
*   **Bitmask:**
    *   Bit 0: Enable hardware watchdog
    *   Bit 1: Disable MAVftp
    *   Bit 3: Enable Debug Pins
    *   Bit 7: Skip board validation