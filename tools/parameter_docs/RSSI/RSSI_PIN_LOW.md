---
layout: parameter
name: RSSI_PIN_LOW
display_name: RSSI Weak Signal Voltage
description: The voltage received when the radio signal is at its weakest.
default_value: 0
range: 0 5.0
units: V
group: RSSI
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_RSSI/AP_RSSI.cpp#L63
---

# RSSI Weak Signal Voltage (RSSI_PIN_LOW)

## Description
`RSSI_PIN_LOW` calibrates the "0% Signal" point for analog RSSI sensors.

You measure this by powering on the drone but keeping the transmitter turned off (or at extreme distance). The voltage reported by the sensor at this state is entered here.

## Tuning & Behavior
*   **Inversion:** If your receiver outputs a *higher* voltage for a *weaker* signal (inverted), simply set `RSSI_PIN_LOW` to the high voltage and `RSSI_PIN_HIGH` to the low voltage.