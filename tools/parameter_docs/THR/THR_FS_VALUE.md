---
layout: parameter
name: THR_FS_VALUE
display_name: Throttle Failsafe PWM Threshold (Plane)
description: The PWM value on the throttle channel below which an RC failsafe is triggered.
default_value: 950
range: 925 1100
units: PWM
group: THR
visual_asset_id: failsafe_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduPlane/Parameters.cpp#L429
---

# Throttle Failsafe PWM Threshold (THR_FS_VALUE)

## Description
`THR_FS_VALUE` defines the "Signal Lost" voltage for your radio receiver.

Most receivers are configured to pull the throttle channel to a very low value (e.g. 900) if the link is broken. This parameter tells the autopilot: "If the throttle drops below 950, assume the radio is off and start the failsafe routine."

## Tuning & Behavior
*   **Default:** 950.
*   **Setup:** Turn off your transmitter and see what the throttle PWM value is in the GCS. Set this parameter to about **10-20 units above** that value, but well below your normal idle throttle (usually 1100).