---
layout: parameter
name: TRQD_DIR_DELAY
display_name: Torqeedo Direction Change Delay
description: The pause time (in seconds) enforced when switching between forward and reverse thrust.
default_value: 0.5
range: 0 2.0
units: s
group: TRQD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Torqeedo/AP_Torqeedo_Params.cpp#L61
---

# Torqeedo Direction Change Delay (TRQD_DIR_DELAY)

## Description
`TRQD_DIR_DELAY` protects the motor's gearbox and electronics from high-torque reversals.

Electric boat motors generate massive torque. Attempting to switch from full-forward to full-reverse instantly can strip gears or blow electrical fuses. This parameter introduces a mandatory "neutral" pause to allow the propeller to slow down before it is powered in the opposite direction.

## Tuning & Behavior
*   **Default:** 0.5 seconds.
*   **Recommendation:** Set to **1.0 second** for larger propellers to ensure a smooth and safe transition.