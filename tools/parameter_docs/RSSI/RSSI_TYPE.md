---
layout: parameter
name: RSSI_TYPE
display_name: RSSI Type
description: Radio Receiver RSSI type. If your radio receiver supports RSSI of some kind, set it here, then set its associated RSSI_XXXXX parameters, if any.
default_value: 0
range: 0 5
units: 
group: RSSI
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_RSSI/AP_RSSI.cpp#L40
---

# RSSI_TYPE: RSSI Type

## Description
Radio Receiver RSSI type. This selects the method used to read the signal strength (RSSI) from your radio link.

## Values
| Value | Meaning |
| :--- | :--- |
| 0 | Disabled |
| 1 | Analog Pin (Voltage on a specific flight controller pin) |
| 2 | RC Channel PWM (RSSI value embedded in a spare RC channel) |
| 3 | Receiver Protocol (Digital info from SBUS, CRSF, or FPort) |
| 4 | PWM Input Pin (RSSI sent as a high-frequency PWM signal) |
| 5 | Telemetry Radio RSSI (RSSI reported back from SiK/MAVLink radios) |

- **Default:** 0

## Description
`RSSI_TYPE` tells the autopilot how to measure the "health" of your radio control link.

- **Receiver Protocol (3):** The modern standard. If you are using ELRS, Crossfire, or FrSky FPort, the RSSI is sent digitally inside the data stream. Set this to 3 and no other wiring is needed.
- **RC Channel (2):** Common for older FrSky setups where you map RSSI to an auxiliary channel (e.g., Channel 8 or 16).
- **Analog (1):** Used for very old receivers that output a 0-3.3V signal.

## Source Code
[ardupilot/libraries/AP_RSSI/AP_RSSI.cpp](https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_RSSI/AP_RSSI.cpp#L40)
