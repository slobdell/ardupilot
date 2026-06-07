---
layout: parameter
name: NTF_LED_BRIGHT
display_name: Onboard LED Brightness
description: Selects the brightness level for the status RGB LEDs.
default_value: 3
range: 1 3
units: 
group: NTF
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Notify/AP_Notify.cpp#L162
---

# Onboard LED Brightness (NTF_LED_BRIGHT)

## Description
`NTF_LED_BRIGHT` controls how intense the status LEDs (e.g. the big blinking LED on a Pixhawk) appear. 

*   **1: Low.** Dim, good for night flight or bench testing.
*   **2: Medium.**
*   **3: High (Default).** Bright enough to be seen in direct sunlight.

## Tuning & Behavior
*   **Safety Feature:** When the flight controller is powered via **USB**, the brightness is automatically forced to **Low** to prevent over-current on the USB rail and to avoid blinding the developer. The high setting only takes effect when powered by a battery.