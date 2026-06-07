---
layout: parameter
name: AIS_LOGGING
display_name: AIS logging options
description: Bitmask of AIS logging options.
default_value: 6
range: 
units: 
group: AIS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_AIS/AP_AIS.cpp
---

# AIS logging options (AIS_LOGGING)

## Description
Controls which AIS messages are recorded in the data logs.

## Tuning & Behavior
*   **Default Value:** 6 (AIS_OPTIONS_LOG_UNSUPPORTED_RAW | AIS_OPTIONS_LOG_DECODED)
*   **Bitmask:**
    *   0: Log all AIVDM messages
    *   1: Log only unsupported AIVDM messages
    *   2: Log decoded messages