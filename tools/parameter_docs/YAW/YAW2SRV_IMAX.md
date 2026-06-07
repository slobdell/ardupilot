---
layout: parameter
name: YAW2SRV_IMAX
display_name: Yaw Integrator Limit
description: Limits how far the rudder can be moved by the automatic trim system (integrator).
default_value: 1500
range: 0 4500
units: cdeg
group: YAW
visual_asset_id: yaw_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/APM_Control/AP_YawController.cpp#L64
---

# Yaw Integrator Limit (YAW2SRV_IMAX)

## Description
`YAW2SRV_IMAX` prevents the automatic rudder trim from taking over the entire plane.

It limits how many degrees of deflection the [YAW2SRV_INT](YAW2SRV_INT.html) term can command. If your plane is badly out of alignment, the integrator could theoretically "Walk" the rudder all the way to its mechanical limit. This safety cap ensures you always have visual control remaining.

*   **Default:** 1500 (1/3rd of the total rudder travel).
