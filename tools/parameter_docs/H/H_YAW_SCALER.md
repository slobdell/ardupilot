---
layout: parameter
name: H_YAW_SCALER
display_name: Yaw Axis Gain Scaler
description: A multiplier to increase or decrease the overall yaw control authority for dual-rotor helicopters.
default_value: 1.0
range: 0 2
units: 
group: H
visual_asset_id: heli_dual_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Motors/AP_MotorsHeli_Dual.cpp#L100
---

# Yaw Axis Gain Scaler (H_YAW_SCALER)

## Description
`H_YAW_SCALER` is specific to **Dual Rotor** helicopters (like Coaxial or Tandem designs).

It provides a master gain for the yaw axis. Because dual-rotor helis use complex torque-matching or differential pitch to yaw, the standard PID gains might not have enough range. This parameter allows you to scale the entire output to get the desired yaw rate.

## Tuning & Behavior
*   **Default Value:** 1.0.
*   **Recommendation:** If the helicopter is lazy in yaw even with high P-gains, increase this to **1.5**.
*   **Safety:** Only active for Dual Heli builds.
