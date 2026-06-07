---
layout: parameter
name: SAFE_DISARM_PWM
display_name: "PWM that will be output when disarmed or in stop mode"
description: "Controls the servo output behavior when the Tracker is disarmed"
default_value: 0
range: 0 1
units: ""
group: SAFE
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/AntennaTracker/Parameters.cpp#L552
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# PWM that will be output when disarmed or in stop mode (SAFE_DISARM_PWM)

## Description
This parameter determines the signal sent to the servos when the Antenna Tracker is in a disarmed state or "Stop" mode. It is a safety feature to ensure the tracker does not move unexpectedly or holds a neutral position when not actively tracking.

## The Mathematics
The parameter acts as a selector for the output logic:
*   **0:** Zero PWM (Output = 0). Depending on the hardware/HAL, this may mean sending no signal pulses (servos go limp) or sending a 0us pulse width.
*   **1:** Trim PWM. The servos are commanded to their trim (center) position.

## The Engineer's View
Defined in `AntennaTracker/Parameters.cpp` and used in `tracking.cpp`. The values map to the `PWMDisarmed` enum:
*   `ZERO` (0)
*   `TRIM` (1)

## Tuning & Behavior
*   **Default Value:** 0
*   **0 (Zero PWM):** Servos are typically unpowered (signal-wise) and can be moved by hand (if digital servos support this) or stay in their last position.
*   **1 (Trim PWM):** Servos are actively held at their centered/neutral position.