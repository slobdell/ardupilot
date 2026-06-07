---
layout: parameter
name: H_SW2_H3_PHANG
display_name: Swashplate 2 Phase Angle
description: The phase angle (in degrees) for the second swashplate to account for gyroscopic precession.
default_value: 0
range: -30 30
units: deg
group: H
visual_asset_id: heli_swash_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Motors/AP_MotorsHeli_Dual.cpp#L25
---

# Swashplate 2 Phase Angle (H_SW2_H3_PHANG)

## Description
`H_SW2_H3_PHANG` corrects the timing of the second rotor's control inputs. 

Because of gyroscopic precession, pushing the swashplate "Forward" doesn't always make the blades tilt "Forward." This parameter adds an offset (Lead/Lag) to align the physical tilt with the intended movement.

## Tuning & Behavior
*   **Default Value:** 0.
*   **Tuning:** Hover the heli and push the Pitch stick. If the heli also rolls, adjust this value until the roll component is gone.