---
layout: parameter
name: EK3_DRAG_BCOEF_X
display_name: Ballistic coefficient for X axis drag
description: Ratio of mass to drag coefficient along the X body axis. Enables wind drift estimation for multirotors.
default_value: 0.0
range: 0.0 1000.0
units: kg/m^2
group: EK3
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_NavEKF3/AP_NavEKF3.cpp
---

# Ballistic coefficient for X axis drag (EK3_DRAG_BCOEF_X)

## Description
A physical parameter representing the aerodynamic drag of the aircraft's body in the forward/backward direction. When set, it allows the EKF to estimate wind velocity based on the tilt required to maintain position.
*   **Set to > 0 to enable wind estimation for multirotors.**
