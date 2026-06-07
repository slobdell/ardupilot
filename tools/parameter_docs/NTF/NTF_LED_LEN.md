---
layout: parameter
name: NTF_LED_LEN
display_name: Serial LED String Length
description: The total number of individually addressable LEDs (NeoPixels/ProfiLED) in the status string.
default_value: 1
range: 1 32
units: LEDs
group: NTF
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Notify/AP_Notify.cpp#L230
---

# Serial LED String Length (NTF_LED_LEN)

## Description
`NTF_LED_LEN` defines how many NeoPixel-style LEDs are in your status light strip.

ArduPilot can control a chain of addressable RGB LEDs to provide super-bright, high-visibility status notifications (like green for "Home Set" or flashing yellow for "Radio Failsafe"). 

*   **1 (Default):** Standard single status LED.
*   **1-32:** Number of LEDs in your physical strip.

## Tuning & Behavior
*   **Usage:** Set this to match the number of LEDs you have physically wired to your serial LED port.
*   **Power Warning:** Addressable LEDs consume significant current. If you use a long string (e.g., 20+ LEDs), ensure your flight controller's 5V regulator can handle the load, or use an external BEC.