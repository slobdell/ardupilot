---
layout: parameter
name: YAW_RATE_IMAX
display_name: Yaw Rate I Max
description: The maximum command limit for the yaw integrator.
default_value: 0.222
range: 0 1.0
units: 
group: YAW
visual_asset_id: yaw_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl.cpp#L100
---

# Yaw Rate I Max (YAW_RATE_IMAX)

## Description
`YAW_RATE_IMAX` limits how much power the "Memory" (I-Term) can use to fix a yaw error.

*   **0.222 (Default):** The integrator can use up to 22.2% of the motor range.
*   **1.0:** The integrator can use 100% of the motor range. (Dangerous!).

## Tuning & Behavior
*   **Safety:** This prevents "Wind-Up." If you block the drone's rotation with your hand, the integrator would normally keep building up power to try and move it. `IMAX` caps that power so the drone doesn't explode when you let go.