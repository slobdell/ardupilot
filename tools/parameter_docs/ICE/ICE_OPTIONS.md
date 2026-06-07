---
layout: parameter
name: ICE_OPTIONS
display_name: ICE Options
description: A bitmask of options to customize internal combustion engine safety and logic behaviors.
default_value: 0
range: 0 31
units: 
group: ICE
visual_asset_id: ice_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_ICEngine/AP_ICEngine.cpp#L125
---

# ICE Options (ICE_OPTIONS)

## Description
`ICE_OPTIONS` provides a set of "Safety Toggles" for engine operation.

*   **Bit 0 (1): Disable ignition in RC failsafe.**
    If you lose radio link, the autopilot instantly cuts the ignition. Safer for large vehicles.
*   **Bit 2 (4): Throttle control in MANUAL while disarmed.**
    Allows the pilot to test throttle movement and adjust the carburetor even when the motors are "disarmed."
*   **Bit 3 (8): Disable while disarmed.**
    Prevents the engine from starting unless the flight controller is fully armed. 
*   **Bit 4 (16): Crank direction Reverse.**
    Reverses the direction of the starter motor (requires hardware support, e.g., TCA9554).

## Tuning & Behavior
*   **Default Value:** 0.
*   **Recommendation:** Enable **Bit 0** for high-risk operations to ensure the engine stops if the controller is no longer in command.