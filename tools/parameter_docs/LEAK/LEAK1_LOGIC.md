---
layout: parameter
name: LEAK1_LOGIC
display_name: Leak Sensor Logic (Sensor 1)
description: Defines the expected electrical state (high/low) of the sensor when it is dry.
default_value: 0
range: 0 1
units: 
group: LEAK
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_LeakDetector/AP_LeakDetector.cpp#L20
---

# Leak Sensor Logic (LEAK1_LOGIC)

## Description
`LEAK1_LOGIC` calibrates the autopilot for your specific leak sensor hardware.

*   **0: Low when dry (Default).** The sensor reports a logical 0 when no water is present.
*   **1: High when dry.** The sensor reports a logical 1 when dry.

## Tuning & Behavior
*   **Calibration:** If your GCS reports a "LEAK" error even when the ROV is completely dry, try toggling this parameter.
*   **Safety:** Always test your leak sensor manually (e.g. by bridging the contacts with a damp cloth) before diving to ensure the autopilot correctly detects the alarm state.