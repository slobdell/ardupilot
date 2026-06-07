---
layout: parameter
name: RPM1_PIN
display_name: RPM Input Pin (Sensor 1)
description: The physical GPIO pin used to read the RPM pulse signal.
default_value: -1
range: -1 103
units: 
group: RPM
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_RPM/AP_RPM_Params.cpp#L62
---

# RPM Input Pin (RPM1_PIN)

## Description
`RPM1_PIN` tells the autopilot which digital port on the flight controller is connected to your RPM sensor (e.g., an optical sensor, a hall effect sensor, or the RPM output from an ESC).

*   **-1:** Disabled.
*   **0-103:** The pin number assigned to the physical input.

## Tuning & Behavior
*   **Default:** -1.
*   **Setup:** Refer to your flight controller's documentation to find the correct GPIO pin number for the port you are using.
*   **Requirement:** Only used if `RPM1_TYPE` is set to **1 (GPIO)**.