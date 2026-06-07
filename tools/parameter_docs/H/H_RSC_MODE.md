---
layout: parameter
name: H_RSC_MODE
display_name: Rotor Speed Control Mode
description: Selects the method used to control the main rotor speed.
default_value: 1
range: 1 4
units: 
group: H
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Motors/AP_MotorsHeli_RSC.cpp
---

# Rotor Speed Control Mode (H_RSC_MODE)

## Description
Configures how the flight controller determines the throttle output for the main rotor.
*   **1: RC Passthrough (Direct control from transmitter)**
*   **2: External Gov SetPoint (Uses H_RSC_SETPOINT)**
*   **3: Throttle Curve (Uses 5-point curve based on collective)**
*   **4: AutoThrottle (Advanced internal governor requiring RPM sensor)**