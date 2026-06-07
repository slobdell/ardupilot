---
layout: parameter
name: NTF_BUZZ_PIN
display_name: Buzzer Output Pin
description: The physical GPIO pin used for the status buzzer.
default_value: -1
range: -1 103
units: 
group: NTF
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Notify/AP_Notify.cpp#L201
---

# Buzzer Output Pin (NTF_BUZZ_PIN)

## Description
`NTF_BUZZ_PIN` tells the autopilot which pin is connected to the piezo buzzer.

The buzzer is used for audible feedback, such as "Ready to Arm" beeps, low battery sirens, and SOS codes for sensor failures.

## Tuning & Behavior
*   **Default:** -1 (Use the board's default buzzer pin).
*   **Usage:** If you are building a custom drone and want to move the buzzer to a different output (e.g., AUX 5), you can enter that GPIO number here.
*   **Hardware Requirement:** Note that standard flight controller pins provide very little current. If you are using a large, loud buzzer, you may need a small MOSFET or transistor circuit between the FC and the buzzer.