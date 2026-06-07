---
layout: parameter
name: ARMING_REQUIRE
display_name: Require Arming Motors
description: Arming disabled until some requirements are met. If 0, there are no requirements (arm immediately).
default_value: 1
range: 0 2
units: 
group: ARMING
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Arming/AP_Arming.cpp
---

# Require Arming Motors (ARMING_REQUIRE)

## Description
Determines if an explicit arming command (from GCS or RC sticks) is required to enable motor output.

## Tuning & Behavior
*   **Default Value:** 1
*   **Values:**
    *   0: Disabled (Arm immediately on boot)
    *   1: Enabled (Minimum PWM when disarmed)
    *   2: Enabled (0 PWM when disarmed)
*   **A value of 1 or 2 is strongly recommended for safety.**
