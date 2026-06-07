---
layout: parameter
name: TRQD_ONOFF_PIN
display_name: Torqeedo Power Control Pin
description: The physical GPIO pin used to turn the Torqeedo motor on and off.
default_value: -1
range: -1 103
units: 
group: TRQD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Torqeedo/AP_Torqeedo_Params.cpp#L21
---

# Torqeedo Power Control Pin (TRQD_ONOFF_PIN)

## Description
`TRQD_ONOFF_PIN` allows ArduPilot to electronically "Push the Power Button" on your Torqeedo motor.

Torqeedo motors require a specific startup sequence. By connecting a GPIO pin to the motor's power control line, the autopilot can automatically wake the motor up when the boat is armed and put it to sleep when disarmed, saving battery and ensuring readiness.

*   **-1:** Disabled (Manual power control).
*   **0-103:** Physical GPIO pin number.

## Tuning & Behavior
*   **Recommendation:** Use the serial port's RTS pin if your hardware supports it, as it provides a clean, dedicated signal line for this purpose.