---
layout: parameter
name: MOT_FV_CPLNG_K
display_name: 6-DOF Pitch Decoupling Gain
description: Compensates for the inherent coupling between forward/vertical thrust and pitch for omnicopters.
default_value: 1.0
range: 0 1.5
units: 
group: MOT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Motors/AP_Motors6DOF.cpp#L91
---

# 6-DOF Pitch Decoupling Gain (MOT_FV_CPLNG_K)

## Description
`MOT_FV_CPLNG_K` is an advanced tuning parameter for **6-DOF** (Omnidirectional) multicopters.

In a traditional drone, moving forward requires pitching the nose down. In a 6-DOF drone, the motors are tilted so you can move forward while staying perfectly level. However, applying forward thrust often creates a slight, unintended "Nod" in the pitch axis due to the motor geometry. This parameter applies a mathematical correction to "cancel out" that coupling.

*   **0:** Disabled.
*   **1.2:** Typical "Normal" value for most 6-DOF frames.

## Tuning & Behavior
*   **Default:** 1.0.
*   **Calibration:** Fly your 6-DOF drone and command a pure forward translation. If the drone pitches down as it accelerates, increase this value. If it pitches up, decrease it.
*   **Context:** Only used if your motor layout is configured for 6-DOF control.