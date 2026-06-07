---
layout: parameter
name: WNDVN_DIR_PIN
display_name: Wind Vane Direction Pin
description: The analog input pin used to read the wind vane direction voltage.
default_value: -1
range: -1 103
units: 
group: WNDVN
visual_asset_id: windvane_pin_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_WindVane/AP_WindVane.cpp#L55
---

# Wind Vane Direction Pin (WNDVN_DIR_PIN)

## Description
`WNDVN_DIR_PIN` sets the physical analog pin on the flight controller where the wind vane's direction signal is connected. 

This parameter is only used if `WNDVN_TYPE` is set to 3 (Analog).

*   **-1: Not used.**
*   **0-9: Analog Pin Number.** (e.g., 0 for A0).
*   **50-55: AUX Out Pins.** (When configured as analog inputs).
*   **103: RSSI/SBUS pin.** (On some hardware).

## Tuning & Behavior
*   **Default:** -1.
*   **Selection:** Consult your flight controller's hardware documentation (GPIO/Analog Pin mapping) to find the correct number for the pin you have used.