---
layout: parameter
name: LEAK1_PIN
display_name: Leak Detector Pin (Sensor 1)
description: The physical pin number connected to the first leak detector.
default_value: -1
range: -1 103
units: 
group: LEAK
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_LeakDetector/AP_LeakDetector.cpp#L13
---

# Leak Detector Pin (LEAK1_PIN)

## Description
`LEAK1_PIN` sets the physical pin on the flight controller where the leak sensor's signal is connected.

*   **-1: Not used.**
*   **0-9: Analog Pin Number.**
*   **50-55: AUX Out Pins.**

## Tuning & Behavior
*   **Default:** -1.
*   **Action:** Ensure the pin matches your hardware wiring.