---
layout: parameter
name: DID_OPTIONS
display_name: OpenDroneID options
description: Bitmask of options for the OpenDroneID subsystem.
default_value: 0
range: 
units: 
group: DID
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_OpenDroneID/AP_OpenDroneID.cpp
---

# OpenDroneID options (DID_OPTIONS)

## Description
Configuration bitmask for Remote ID enforcement and identity locking.

## Tuning & Behavior
*   **Default Value:** 0
*   **Bitmask:**
    *   Bit 0: EnforceArming (Refuse to arm if Remote ID is not healthy)
    *   Bit 1: AllowNonGPSPosition
    *   Bit 2: LockUASIDOnFirstBasicIDRx