---
layout: parameter
name: Q_TILT_TYPE
display_name: Tilt Rotor Type
description: Selects the mechanical type of the tilt rotor mechanism.
default_value: 0
range: 0 3
units: 
group: Q
visual_asset_id: vtol_tilt_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# Tilt Rotor Type (Q_TILT_TYPE)

## Description
`Q_TILT_TYPE` tells ArduPilot how your tilting mechanism works.

*   **0: Continuous.** A standard servo that can move smoothly to any angle between 0 and 90.
*   **1: Binary.** A retract mechanism that only has two positions (Up/Down).
*   **2: Vectored Yaw.** The tilt servos are also used for yaw control in forward flight (like a V-22 Osprey).

## Tuning & Behavior
*   **Default Value:** 0.