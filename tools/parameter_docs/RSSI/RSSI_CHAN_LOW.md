---
layout: parameter
name: RSSI_CHAN_LOW
display_name: RSSI Weak Signal PWM
description: The PWM value representing the weakest radio signal (0%).
default_value: 1000
range: 0 2000
units: PWM
group: RSSI
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_RSSI/AP_RSSI.cpp#L87
---

# RSSI Weak Signal PWM (RSSI_CHAN_LOW)

## Description
`RSSI_CHAN_LOW` calibrates the "Minimum" point for **PWM-based** RSSI sensors or auxiliary channels.

If your receiver is sending RSSI as a PWM signal (where a shorter pulse means a weaker signal), this parameter defines the 0% threshold.

## Tuning & Behavior
*   **Default:** 1000.
*   **Calibration:** Turn off your transmitter and observe the RSSI PWM value in the GCS status tab. Enter that value here.