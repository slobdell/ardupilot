---
layout: parameter
name: ARMING_CHECK
display_name: Arm Checks to Perform (bitmask)
description: Checks prior to arming motor. This is a bitmask of checks that will be performed before allowing arming. For most users it is recommended to leave this at the default of 1 (all checks enabled).
default_value: 1
range: 
units: 
group: ARMING
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Arming/AP_Arming.cpp
---

# Arm Checks to Perform (ARMING_CHECK)

## Description
Bitmask selecting which internal subsystems must pass their health checks before the vehicle is allowed to arm.

## Tuning & Behavior
*   **Default Value:** 1 (All checks enabled)
*   **Bitmask Examples:**
    *   1: All
    *   2: Barometer
    *   4: Compass
    *   8: GPS lock
    *   16: INS (IMU)
    *   32: Parameters
    *   64: RC Channels
*   **Setting to 0 disables all safety checks (NOT RECOMMENDED for flight).**