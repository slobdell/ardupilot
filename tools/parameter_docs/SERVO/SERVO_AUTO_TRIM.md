---
layout: parameter
name: SERVO_AUTO_TRIM
display_name: Servo Auto Trim
description: Enables automatic servo trim adjustment based on current control inputs.
default_value: 0
range: 0 1
units: 
group: SERVO
visual_asset_id: servo_trim_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SRV_Channel/SRV_Channel.cpp#L100
---

# Servo Auto Trim (SERVO_AUTO_TRIM)

## Description
`SERVO_AUTO_TRIM` simplifies the process of trimming a plane.

Instead of manually adjusting linkages or radio trims, you can fly the plane level, and the autopilot will slowly learn the new center positions for the servos.

## Tuning & Behavior
*   **0:** Disabled.
*   **1:** Enabled.
*   **Note:** Usually activated via an RC switch option (`RCx_OPTION` = 155) rather than setting this parameter permanently.