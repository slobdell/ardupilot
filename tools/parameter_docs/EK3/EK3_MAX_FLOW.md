---
layout: parameter
name: EK3_MAX_FLOW
display_name: "Maximum valid optical flow rate"
description: "Maximum optical flow rate accepted by the filter"
default_value: 2.5f
range: 1.0 4.0
units: "rad/s"
group: EK3
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_NavEKF3/AP_NavEKF3.cpp#L311
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_NavEKF3/AP_NavEKF3.h#L414
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Maximum valid optical flow rate (EK3_MAX_FLOW)

## Description
This parameter sets a hard limit on the optical flow rate (angular velocity of the visual texture) that the Extended Kalman Filter (EKF) will accept. If the flow sensor reports a value higher than this, it is assumed to be a glitch (e.g., lighting change, shadow, or sensor error) or a maneuver exceeding the sensor's capability, and the measurement is rejected to prevent position divergence.

## The Mathematics
$$ \text{Reject} \iff \|\vec{\omega}_{\text{flow}}\| > \text{EK3\_MAX\_FLOW} $$

## The Engineer's View
Defined in `libraries/AP_NavEKF3/AP_NavEKF3.cpp`. Used in the optical flow fusion logic. High flow rates often correlate with poor signal quality or motion blur, making the data unreliable.

## Tuning & Behavior
*   **Default Value:** 2.5 rad/s (~143 deg/s)
*   **Range:** 1.0 - 4.0 rad/s
*   **Tuning:** Increase slightly for highly agile quadcopters flying close to the ground, but be aware that sensor noise often increases at high rates.