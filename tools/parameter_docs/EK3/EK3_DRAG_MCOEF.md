---
layout: parameter
name: EK3_DRAG_MCOEF
display_name: Momentum coefficient for propeller drag
description: Predicts drag produced by the rotors when flying a multicopter, enabling wind drift estimation.
default_value: 0.0
range: 0.0 1.0
units: 1/s
group: EK3
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_NavEKF3/AP_NavEKF3.cpp
---

# Momentum coefficient for propeller drag (EK3_DRAG_MCOEF)

## Description
Accounts for the "rotor drag" effect where air velocity normal to the rotor disc is lost, creating a force. This is distinct from body drag and is essential for accurate wind estimation on multicopters.
