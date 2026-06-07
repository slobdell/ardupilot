---
layout: parameter
name: RSSI_CHAN_HIGH
display_name: RSSI Strong Signal PWM
description: The PWM value representing the strongest radio signal (100%).
default_value: 2000
range: 0 2000
units: PWM
group: RSSI
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_RSSI/AP_RSSI.cpp#L95
---

# RSSI Strong Signal PWM (RSSI_CHAN_HIGH)

## Description
`RSSI_CHAN_HIGH` calibrates the "Maximum" point for **PWM-based** RSSI sensors or auxiliary channels.

If your receiver is sending RSSI as a PWM signal, this parameter defines the 100% threshold.

## Tuning & Behavior
*   **Default:** 2000.
*   **Calibration:** Place your transmitter near the drone and observe the RSSI PWM value in the GCS. Enter that value here.