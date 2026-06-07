---
layout: parameter
name: SIM_SF_JS_AXIS1
display_name: Simulation SFML Joystick Axis 1
description: Maps the first physical joystick axis to a virtual input in SITL.
default_value: 0
range: 0 7
units: 
group: SIM
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/SITL/SITL.cpp#L1083
---

# Simulation SFML Joystick Axis 1 (SIM_SF_JS_AXIS1)

## Description
`SIM_SF_JS_AXIS1` (and AXIS2 through AXIS8) allows you to rebind the physical axes of your controller to the expected inputs in the simulator. 

By default, Axis 1 is typically mapped to the X-axis (Roll/Aileron) of the joystick.

## Tuning & Behavior
*   **Axis Mapping:** The value corresponds to the SFML `sf::Joystick::Axis` enum (X, Y, Z, R, U, V, PovX, PovY).
*   **Configuration:** If your controls are swapped (e.g. throttle is on the wrong stick), use these parameters to realign them.