---
layout: parameter
name: FS_VIBE_ENABLE
display_name: Vibration Failsafe Enable
description: Enables the automatic detection of excessive vibration levels, which can trigger a fallback to more robust but less precise position estimation logic.
default_value: 1
range: 0 1
units: 
group: FS
visual_asset_id: failsafe_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduCopter/Parameters.cpp#L100
---

# Vibration Failsafe Enable (FS_VIBE_ENABLE)

## Description
`FS_VIBE_ENABLE` activates a "Limp Mode" for drones suffering from extreme vibration.

If a drone has a damaged propeller or a loose motor, the resulting vibrations can overwhelm the EKF, making the drone fly erratically or drift away. When this failsafe is enabled, the autopilot detects the high vibration and automatically switches to a simpler navigation model that is less accurate but far more resistant to vibration noise.

*   **0: Disabled.**
*   **1: Enabled (Default).**