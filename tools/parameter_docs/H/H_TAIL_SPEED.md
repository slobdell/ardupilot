---
layout: parameter
name: H_TAIL_SPEED
display_name: DDVP Tail ESC speed
description: The motor speed (percentage) for direct-drive variable pitch (DDVP) tail rotors.
default_value: 0
range: 0 100
units: %
group: H
visual_asset_id: heli_tail_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Motors/AP_MotorsHeli_Single.cpp#L66
---

# DDVP Tail ESC speed (H_TAIL_SPEED)

## Description
`H_TAIL_SPEED` sets the target RPM for a **Direct Drive Variable Pitch (DDVP)** tail.

In this setup, the tail rotor is spun by its own motor at a constant speed, while a servo changes the blade pitch to control yaw. This parameter defines how much power is sent to the tail motor ESC.

## Tuning & Behavior
*   **Default Value:** 0.
*   **Recommendation:** Set high enough to ensure the tail has enough authority to counter main rotor torque during high-load maneuvers, but not so high that you waste battery or stress the motor.
