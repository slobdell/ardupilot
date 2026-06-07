---
layout: parameter
name: QWIK_OSC_SMAX
display_name: Quicktune Oscillation Threshold
description: The threshold for detecting oscillations during the tuning process. A lower value leads to a more conservative tune.
default_value: 4
range: 1 10
units: 
group: QWIK
visual_asset_id: quicktune_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Quicktune/AP_Quicktune.cpp#L53
---

# Quicktune Oscillation Threshold (QWIK_OSC_SMAX)

## Description
`QWIK_OSC_SMAX` defines how much "Shaking" the autopilot allows before it decides the gain is too high.

The system monitors the "Slew Rate" (how fast the motors are changing speed) to detect the onset of high-frequency oscillations.

*   **Lower Value (1-2):** Very sensitive. Quicktune will stop increasing gains at the first hint of a vibration.
*   **Higher Value (6-10):** Less sensitive. Allows the drone to shake more violently before backing off.

## Tuning & Behavior
*   **Default Value:** 4.
*   **Recommendation:** Leave at **4**. Only increase this if you find that Quicktune is stopping prematurely due to noise from imbalanced propellers or a loose frame.