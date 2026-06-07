---
layout: parameter
name: H_OPTIONS
display_name: Heli_Options
description: Bitmask of helicopter-specific options.
default_value: 1
range: 
units: 
group: H
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Motors/AP_MotorsHeli.cpp
---

# Heli_Options (H_OPTIONS)

## Description
Configuration bitmask for helicopter flight behaviors.
*   **Bit 0: Use Leaky I (Recommended for most setups to prevent integrator windup on the ground).**
