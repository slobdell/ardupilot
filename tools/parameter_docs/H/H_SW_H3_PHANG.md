---
layout: parameter
name: H_SW_H3_PHANG
display_name: H3 Generic Phase Angle Comp
description: The phase angle (in degrees) used to correct for gyroscopic precession errors in the swashplate rotation.
default_value: 0
range: -30 30
units: deg
group: H
visual_asset_id: heli_swash_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Motors/AP_MotorsHeli_Swash.cpp#L45
---

# H3 Generic Phase Angle Comp (H_SW_H3_PHANG)

## Description
`H_SW_H3_PHANG` corrects for "Control Coupling" – a common issue on helicopters where a pitch command causes a roll, or vice versa.

Because of gyroscopic precession, a force applied to the main rotor blades takes effect 90 degrees later in the rotation. If your swashplate linkages are not perfectly aligned with the blade grips, the drone will "drift" sideways when you tell it to go forward. This parameter rotates the virtual control axes to fix that alignment error.

## Tuning & Behavior
*   **Default Value:** 0.
*   **Tuning:** If you push the pitch stick forward and the heli rolls to the right, add a few degrees of phase angle until the movement is purely longitudinal.
