---
layout: parameter
name: SIM_GRPS_PIN
display_name: Gripper Servo Pin
description: The servo output channel (starting at 1) that the virtual gripper is connected to.
default_value: -1
range: -1 16
units: 
group: SIM
visual_asset_id: brd_io_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SIM_Gripper_Servo.cpp#L38
---

# Gripper Servo Pin (SIM_GRPS_PIN)

## Description
`SIM_GRPS_PIN` connects the virtual gripper to a flight controller output.

Set this to match your `SERVOx_FUNCTION = 28` (Gripper) channel. When ArduPilot moves that servo, the simulator will open or close the virtual jaws.

## Tuning & Behavior
*   **Default Value:** -1 (Disabled).
