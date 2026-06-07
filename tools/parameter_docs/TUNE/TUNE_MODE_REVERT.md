---
layout: parameter
name: TUNE_MODE_REVERT
display_name: Tuning Revert on Mode Change
description: Controls if the tuning changes are reset when the pilot changes flight modes.
default_value: 1
range: 0 1
units: 
group: TUNE
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Tuning/AP_Tuning.cpp#L54
---

# Tuning Revert on Mode Change (TUNE_MODE_REVERT)

## Description
`TUNE_MODE_REVERT` is an important safety switch for in-flight tuning.

*   **1: Enabled (Default/Safe).** If you are tuning your drone and it starts to oscillate dangerously, you can simply flick your flight mode switch to any other mode (e.g. from Stabilize to AltHold). The autopilot will immediately discard the current knob position and revert the parameter to the value it had when you started.
*   **0: Disabled.** The tuned value is kept even if you change modes.

## Tuning & Behavior
*   **Recommendation:** Leave at **1 (Enabled)** until you are very comfortable with the tuning process. This provides a "Panic Button" to instantly recover from an unstable tune.
*   **Usage:** Once you find a value you like, you must either "Save" it (using the selector switch or a MAVLink command) or manually enter it into the parameter list before power-cycling.