---
layout: parameter
name: BACKEND_TYPE
display_name: Logging Backend Type
description: Bitmask of logging backends to enable.
default_value: 1
range: 
units: 
group: BACKEND
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Logger/AP_Logger.cpp
---

# Logging Backend Type (BACKEND_TYPE)

## Description
Selects the storage or transmission medium for dataflash logs.

## Tuning & Behavior
*   **Default Value:** 1 (File)
*   **Bitmask:**
    *   Bit 0: File (SD Card)
    *   Bit 1: MAVLink (Streaming to GCS)
    *   Bit 2: Block (Internal Flash)