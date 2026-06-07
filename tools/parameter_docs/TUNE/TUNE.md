---
layout: parameter
name: TUNE
display_name: Channel 6 Tuning (Copter)
description: Selects the parameter (typically a PID gain) to be tuned using the transmitter's Channel 6 knob.
default_value: 0
range: 0 100
units: 
group: TUNE
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduCopter/Parameters.cpp#L326
---

# Channel 6 Tuning (TUNE)

## Description
`TUNE` is the master selector for in-flight parameter adjustment on ArduCopter.

By assigning a knob on your transmitter to Channel 6, you can tune gains while the drone is in the air. This is the fastest way to achieve a perfect tune.

## Values
*   **1:** Roll/Pitch P.
*   **3:** Roll/Pitch I.
*   **4:** Throttle P.
*   **50:** Loiter P.
*   *Refer to the Full List for all 50+ options.*

## Tuning & Behavior
*   **Default:** 0 (Disabled).
*   **Requirement:** Requires [TUNE_MIN](TUNE_MIN.html) and [TUNE_MAX](TUNE_MAX.html) to be set to the safe range for the parameter you are tuning.
*   **Safety:** Always start with the knob in the center (current known good value) and move it slowly.