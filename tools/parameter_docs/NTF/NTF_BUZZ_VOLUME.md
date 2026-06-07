---
layout: parameter
name: NTF_BUZZ_VOLUME
display_name: Buzzer Volume
description: Controls the volume of the onboard status buzzer.
default_value: 100
range: 0 100
units: %
group: NTF
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Notify/AP_Notify.cpp#L222
---

# Buzzer Volume (NTF_BUZZ_VOLUME)

## Description
`NTF_BUZZ_VOLUME` sets the loudness of the beeps and tunes played by the flight controller's buzzer (used for arming alerts, low battery warnings, and error codes).

*   **100:** (Default). Full volume.
*   **0:** Silent (Not recommended for safety reasons).

## Tuning & Behavior
*   **Note:** This only affects hardware buzzers that support volume control via PWM (common on modern Flight Controllers). Simple "Buzzer" pins on older hardware may only support ON/OFF and will ignore this setting.