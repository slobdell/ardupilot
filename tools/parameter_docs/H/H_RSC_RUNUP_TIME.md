---
layout: parameter
name: H_RSC_RUNUP_TIME
display_name: Rotor Runup Time
description: Actual time in seconds for the main rotor to reach full operational speed.
default_value: 10
range: 0 60
units: s
group: H
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Motors/AP_MotorsHeli_RSC.cpp
---

# Rotor Runup Time (H_RSC_RUNUP_TIME)

## Description
Specifies the physical time required for the rotors to reach full speed. This is used by the flight controller to ensure that it doesn't attempt to take off or enter stabilized modes before the rotors have sufficient inertia.
*   **Must be set longer than H_RSC_RAMP_TIME.**
