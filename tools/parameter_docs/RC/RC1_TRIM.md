---
layout: parameter
name: RC1_TRIM
display_name: RC Input Channel 1 Trim
description: The neutral (center) PWM value for RC Input Channel 1.
default_value: 1500
range: 800 2200
units: PWM
group: RC
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/RC_Channel/RC_Channel.cpp#L82
---

# RC Input Channel 1 Trim (RC1_TRIM)

## Description
`RC1_TRIM` defines the "Center" position for the first channel of your radio receiver (typically Roll).

When your transmitter sticks are centered, the receiver sends a specific PWM value. ArduPilot needs to know exactly what that value is so it doesn't think you are trying to turn when you are actually hands-off.

*   **Standard Setting:** 1500 (µs).

## Tuning & Behavior
*   **Calibration:** This value is set automatically when you perform a **Radio Calibration** in your Ground Control Station. You should never need to adjust it manually.
*   **Safety:** If your drone drifts when the sticks are centered, re-run the Radio Calibration rather than manually editing this parameter.