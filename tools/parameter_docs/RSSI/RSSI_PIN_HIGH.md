---
layout: parameter
name: RSSI_PIN_HIGH
display_name: RSSI Strong Signal Voltage
description: The voltage received when the radio signal is at its strongest.
default_value: 3.3
range: 0 5.0
units: V
group: RSSI
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_RSSI/AP_RSSI.cpp#L72
---

# RSSI Strong Signal Voltage (RSSI_PIN_HIGH)

## Description
`RSSI_PIN_HIGH` calibrates the "100% Signal" point for analog RSSI sensors.

You measure this by placing the transmitter immediately next to the drone's receiver. The maximum voltage output by the sensor is entered here.

## Tuning & Behavior
*   **Default:** 3.3V.
*   **Accuracy:** Correctly setting this ensures your GCS shows a full signal bar when you are flying nearby.