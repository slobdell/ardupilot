---
layout: parameter
name: LOG_REPLAY
display_name: Enable logging of information needed for Replay
description: Enables the recording of detailed internal EKF state data required for post-flight Replay analysis.
default_value: 0
range: 0 1
units: 
group: LOG
visual_asset_id: logging_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Logger/AP_Logger.cpp#L134
---

# Enable logging of information needed for Replay (LOG_REPLAY)

## Description
`LOG_REPLAY` is the "Diagnostic Mode" for your EKF.

If you are experiencing "EKF Compass Variance" or "EKF Lane Switch" errors and don't know why, you need to enable this. It records the raw sensor data and internal Kalman filter variables with high precision, allowing developers to "Replay" your actual flight through a simulator to find the bug.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled).
*   **Warning:** Enabling this generates **much larger log files** and increases CPU load. Use it only for troubleshooting, not for standard flying.
*   **Prerequisite:** Requires [LOG_DISARMED](LOG_DISARMED.html) to be set to 1 or 2 to capture the critical pre-flight calibration data.