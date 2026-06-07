---
layout: parameter
name: BARO_GND_TEMP
display_name: Ground Temperature
description: User-provided ground temperature for more accurate altitude estimation.
default_value: 0
range: -50 60
units: degC
group: BARO
visual_asset_id: baro_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Baro/AP_Baro.cpp#L107
---

# Ground Temperature (BARO_GND_TEMP)

## Description
`BARO_GND_TEMP` allows you to manually specify the temperature at the takeoff location. 

ArduPilot uses an "International Standard Atmosphere" (ISA) model to translate pressure changes into altitude. However, air density changes with temperature. If it is very hot or very cold, the standard model will have a significant error (the drone might think it is at 100m when it's really at 110m). Providing the actual ground temperature improves this calculation.

*   **0 (Default):** The autopilot uses the temperature measured by its own internal sensor.
*   **Non-Zero:** Overrides the internal sensor with your manual reading.

## Tuning & Behavior
*   **Default:** 0.
*   **Usage:** For most pilots, leave at **0**. Only change this if you are performing precision survey work or high-altitude balloon flights where temperature gradients are critical.
*   **Note:** This parameter is reset to 0 upon reboot.