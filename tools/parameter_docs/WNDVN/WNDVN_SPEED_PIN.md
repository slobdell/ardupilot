---
layout: parameter
name: WNDVN_SPEED_PIN
display_name: Wind Speed Pin
description: The analog input pin used to read the wind speed sensor voltage.
default_value: -1
range: -1 103
units: 
group: WNDVN
visual_asset_id: windvane_pin_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_WindVane/AP_WindVane.cpp#L130
---

# Wind Speed Pin (WNDVN_SPEED_PIN)

## Description
`WNDVN_SPEED_PIN` sets the physical analog pin on the flight controller where the wind speed sensor's signal is connected. 

This parameter is only used if `WNDVN_SPEED_TYPE` is set to 2 (Modern Devices Analog).

*   **-1: Not used.**
*   **0-9: Analog Pin Number.** (e.g., 0 for A0).
*   **50-55: AUX Out Pins.** (When configured as analog inputs).
*   **103: RSSI/SBUS pin.**

## Tuning & Behavior
*   **Default:** -1.
*   **Configuration:** You must also set [WNDVN_SPEED_OFS](WNDVN_SPEED_OFS.html) to calibrate the voltage at zero wind speed.