---
layout: parameter
name: Q_RC_SPEED
display_name: VTOL Motor Update Rate
description: The frequency (in Hz) at which PWM commands are sent to the VTOL lift motors.
default_value: 490
range: 50 490
units: Hz
group: Q
visual_asset_id: vtol_control_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# VTOL Motor Update Rate (Q_RC_SPEED)

## Description
`Q_RC_SPEED` determines how fast the flight controller talks to your vertical lift motors.

A higher update rate allows the autopilot to make faster corrections, leading to a much more stable hover, especially in wind.

*   **490 Hz:** Standard for high-speed PWM ESCs.
*   **50 Hz:** Legacy analog servos/ESCs.

## Tuning & Behavior
*   **Default Value:** 490 Hz.
*   **Recommendation:** Leave at **490 Hz** for all modern brushless ESCs.
*   **DShot/CAN:** If using DShot or CAN ESCs, this parameter is ignored, as those protocols have their own high-speed timing.