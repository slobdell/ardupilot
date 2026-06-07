---
layout: parameter
name: EK3_GPS_CHECK
display_name: GPS preflight check
description: Bitmap controlling which GPS preflight checks are performed.
default_value: 31
range: 
units: 
group: EK3
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_NavEKF3/AP_NavEKF3.cpp
---

# GPS preflight check (EK3_GPS_CHECK)

## Description
Bitmask selecting which specific GPS quality metrics (sat count, HDOP, velocity consistency) are checked before allowing the EKF to use GPS data or allowing the vehicle to arm.

## Tuning & Behavior
*   **Default Value:** 31 (Standard rigorous checks)
*   **Bitmask Examples:**
    *   Bit 0: sat count
    *   Bit 1: HDOP
    *   Bit 2: speed error
