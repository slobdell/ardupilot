---
layout: parameter
name: GCS_PID_MASK
display_name: GCS PID tuning mask
description: bitmask of PIDs to send MAVLink PID_TUNING messages for.
default_value: 0
range: 
units: 
group: GCS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduCopter/Parameters.cpp
---

# GCS PID tuning mask (GCS_PID_MASK)

## Description
Defines which PID controllers should broadcast their real-time error, proportional, integral, and derivative components over MAVLink (PID_TUNING message). This is essential for ground stations to display real-time PID tuning graphs.

## Tuning & Behavior
*   **Default Value:** 0 (None)
*   **Bitmask (Vehicle dependent):**
    *   Bit 0: Roll
    *   Bit 1: Pitch
    *   Bit 2: Yaw
    *   Bit 3: Altitude/Throttle