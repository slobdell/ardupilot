---
layout: parameter
name: EK3_FLOW_MAX
display_name: EKF3 Optical Flow Max Rate
description: The maximum valid flow rate (in radians/second) accepted by the EKF.
default_value: 2.5
range: 0.5 5.0
units: rad/s
group: EK3
visual_asset_id: flow_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_NavEKF3/AP_NavEKF3.cpp#L100
---

# EKF3 Optical Flow Max Rate (EK3_FLOW_MAX)

## Description
`EK3_FLOW_MAX` filters out bad data from the flow sensor.

Optical flow sensors often glitch when the image moves too fast (motion blur). This parameter tells the EKF to ignore any readings where the flow rate exceeds this limit.

## Tuning & Behavior
*   **Default Value:** 2.5 rad/s.
*   **Recommendation:** Match this to the physical limits of your flow sensor (e.g. CX-OF or HereFlow).