---
layout: parameter
name: RSSI_ANA_PIN
display_name: Receiver RSSI Sensing Pin
description: The physical pin number used to read the analog voltage or PWM RSSI signal from the receiver.
default_value: 0
range: -1 103
units: 
group: RSSI
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_RSSI/AP_RSSI.cpp#L54
---

# Receiver RSSI Sensing Pin (RSSI_ANA_PIN)

## Description
`RSSI_ANA_PIN` tells the autopilot where to look for the "Signal Strength" wire from your radio receiver.

This is only used if you are physically wiring an RSSI output from your receiver to the flight controller. 

*   **Analog Input:** Use an ADC-capable pin (like an analog airspeed port).
*   **PWM Input:** Use a digital GPIO pin (typically a servo output pin configured as a GPIO).

## Tuning & Behavior
*   **Default:** -1 (Disabled).
*   **Calibration:** You must also set the [RSSI_PIN_LOW](RSSI_PIN_LOW.html) and [RSSI_PIN_HIGH](RSSI_PIN_HIGH.html) voltages to calibrate the signal correctly.
*   **Note:** If you are using MAVLink-based RSSI (common with ELRS/Crossfire), this parameter is ignored.