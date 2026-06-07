---
layout: parameter
name: FS_CRASH_CHECK
display_name: Crash Check Enable
description: Enables the automatic crash detection system, which disarms the motors if the drone detects it has crashed.
default_value: 1
range: 0 1
units: 
group: FS
visual_asset_id: failsafe_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduCopter/Parameters.cpp#L100
---

# Crash Check Enable (FS_CRASH_CHECK)

## Description
`FS_CRASH_CHECK` is a major safety feature for multirotors.

It uses the IMU and motor data to detect if the drone has hit an obstacle or flipped on its side. If a crash is detected (e.g., the drone is at an extreme angle and the motors are working hard but not moving it), the autopilot will instantly disarm the motors to prevent further damage or injury from spinning propellers.

*   **0: Disabled.** (Dangerous).
*   **1: Enabled (Default).**

## Tuning & Behavior
*   **Recommendation:** Always leave this enabled. It is one of the most effective ways to prevent "Fly-aways" or ESC fires after a minor collision.