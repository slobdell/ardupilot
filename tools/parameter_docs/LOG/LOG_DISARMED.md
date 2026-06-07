---
layout: parameter
name: LOG_DISARMED
display_name: Enable logging while disarmed
description: Controls whether the flight controller records data while the drone is on the ground (disarmed).
default_value: 0
range: 0 3
units: 
group: LOG
visual_asset_id: logging_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Logger/AP_Logger.cpp#L128
---

# Enable logging while disarmed (LOG_DISARMED)

## Description
`LOG_DISARMED` determines if the "Record" button stays active when the drone is disarmed.

Normally, ArduPilot only logs while you are flying to save SD card space. However, logging on the ground is vital for debugging GPS problems, sensor initialization, or pre-arm failures.

*   **0: Disabled (Default).** Only log when armed.
*   **1: Enabled.** Log constantly as long as the board has power.
*   **2: Disabled on USB.** Log while on battery, but stop when plugged into a computer (to speed up parameter changes).
*   **3: Discard if never armed.** Log while disarmed, but delete the file on reboot if the drone didn't actually take off.

## Tuning & Behavior
*   **Recommendation:** Set to **1** if you are troubleshooting a "Pre-Arm: Needs 3D Fix" or other startup issue. Set to **0** for general use to keep your SD card clean.