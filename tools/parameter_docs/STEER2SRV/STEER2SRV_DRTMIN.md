---
layout: parameter
name: STEER2SRV_DRTMIN
display_name: "Minimum angle of wheel"
description: "Minimum steering angle allowed at maximum speed"
default_value: 4500
range: 0 4500
units: "cdeg"
group: STEER2SRV
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/APM_Control/AP_SteerController.cpp#L114
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/APM_Control/AP_SteerController.h#L67
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Minimum angle of wheel (STEER2SRV_DRTMIN)

## Description
This parameter defines the minimum steering angle (in centi-degrees) that the vehicle will maintain even at maximum speed. While the steering controller generally reduces (derates) the steering angle as speed increases to prevent rollovers, this lower limit ensures the vehicle retains some ability to turn rather than being locked to straight-ahead at full throttle.

## The Mathematics
$$ \theta_{\text{limit}} = \max(\theta_{\text{derated}}, \text{STEER2SRV\_DRTMIN}) $$

## The Engineer's View
Defined in `libraries/APM_Control/AP_SteerController.cpp`.
*   **Safety:** Prevents "Loss of Steering" at high speed.

## Tuning & Behavior
*   **Default Value:** 4500 cdeg (45 degrees). This is quite high and often means no derating floor is applied.
*   **Adjustment:** Decrease to e.g., 500 cdeg (5 degrees) if you want to enforce a very strict limit at high speed.