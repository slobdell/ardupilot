---
layout: parameter
name: H_RSC_GOV_RPM
display_name: Rotor RPM Setting
description: Main rotor RPM that the internal governor maintains when engaged.
default_value: 1500
range: 800 3500
units: RPM
group: H
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Motors/AP_MotorsHeli_RSC.cpp
---

# Rotor RPM Setting (H_RSC_GOV_RPM)

## Description
The target operating speed for the rotors when using the AutoThrottle mode. The flight controller will attempt to maintain this exact RPM using closed-loop control.
*   **Requires a functional RPM sensor.**
