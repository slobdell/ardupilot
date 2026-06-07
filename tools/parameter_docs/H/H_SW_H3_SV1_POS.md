---
layout: parameter
name: H_SW_H3_SV1_POS
display_name: H3 Servo 1 Position
description: The angular position (in degrees) of the first swashplate servo relative to the nose of the helicopter.
default_value: -60
range: -180 180
units: deg
group: H
visual_asset_id: heli_swash_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Motors/AP_MotorsHeli_Swash.cpp#L101
---

# H3 Servo 1 Position (H_SW_H3_SV1_POS)

## Description
`H_SW_H3_SV1_POS` defines the physical location of the first swashplate servo on a 3-servo head.

Angles are measured from the nose (0°).
*   **-60:** Standard position for many RC helicopters (Rear-Left).
*   **60:** Standard position (Rear-Right).
*   **180:** Standard position (Front).

## Tuning & Behavior
*   **Usage:** Only used if [H_SW_H3_ENABLE](H_SW_H3_ENABLE.html) is set to 1.