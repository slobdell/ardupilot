---
layout: parameter
name: RPM1_MIN_QUAL
display_name: Minimum RPM Quality (Sensor 1)
description: The confidence threshold (0-1.0) required to trust the RPM data.
default_value: 0.5
range: 0 1.0
units: 
group: RPM
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_RPM/AP_RPM_Params.cpp#L55
---

# Minimum RPM Quality (RPM1_MIN_QUAL)

## Description
`RPM1_MIN_QUAL` defines the "Certainty Threshold" for digital RPM sensors.

Some RPM sensors (especially those reporting via DroneCAN) calculate a confidence or quality score based on the stability of the signal. If the signal is weak or inconsistent (due to electrical noise or poor sensor alignment), the quality score drops. This parameter tells the autopilot to reject any data if the quality falls below this level.

*   **0.5 (Default):** 50% confidence required.
*   **1.0:** Perfectly clean signal required.

## Tuning & Behavior
*   **Recommendation:** Leave at **0.5**. If you see your RPM readings "flickering" to 0 during high-speed flight, you may need to decrease this value slightly or check your wiring for noise.