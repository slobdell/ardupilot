---
layout: parameter
name: YAW2SRV_DAMP
display_name: Yaw Damping Gain (Fixed-Wing)
description: The gain from measured yaw rate to rudder output.
default_value: 0
range: 0 2.0
units: 
group: YAW2SRV
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/APM_Control/AP_YawController.cpp#L52
---

# Yaw Damping Gain (YAW2SRV_DAMP)

## Description
`YAW2SRV_DAMP` is the primary tool for stopping a plane's tail from "wagging."

In a fixed-wing aircraft, aerodynamic forces or sudden wind gusts can cause the tail to swing left and right (Yaw Oscillation). This parameter applies a counter-force via the rudder based on the yaw rate measured by the gyro. It "resists" fast rotation on the yaw axis, leading to a much smoother and more stable flight path.

## Tuning & Behavior
*   **Default:** 0 (Disabled).
*   **Recommendation:** Start with **0.1** and increase in small increments. 
*   **Optimal Setting:** The plane should fly straight and true, even in turbulent air, without any noticeable oscillating or "hunting" behavior from the rudder.
*   **Dependency:** This should be tuned after setting the basic rudder mix ([KFF_RDDRMIX](KFF_RDDRMIX.html)).