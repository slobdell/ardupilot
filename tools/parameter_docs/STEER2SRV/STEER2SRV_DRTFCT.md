---
layout: parameter
name: STEER2SRV_DRTFCT
display_name: Ground Steering Derating Factor
description: The amount to reduce steering authority (in deg/m/s) as ground speed increases.
default_value: 10
range: 0 50.0
units: deg/m/s
group: STEER2SRV
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/APM_Control/AP_SteerController.cpp#L105
---

# Ground Steering Derating Factor (STEER2SRV_DRTFCT)

## Description
`STEER2SRV_DRTFCT` is a safety parameter for fixed-wing aircraft with a steerable nose or tail wheel.

At very low speeds (taxiing), you need full steering authority to navigate around obstacles. However, at high speeds (takeoff roll), a tiny steering movement can cause the plane to veer wildly or even roll over. This parameter automatically "numbs" the steering wheel as the plane speeds up.

## Tuning & Behavior
*   **Default:** 10 deg/m/s.
*   **Requirement:** Only takes effect when the speed exceeds [STEER2SRV_DRTSPD](STEER2SRV_DRTSPD.html).
*   **Effect:** For every additional meter per second of speed above the threshold, the maximum steering angle is reduced by this many degrees.
*   **Recommendation:** Increase this value if your plane is "twitchy" or difficult to keep straight on the runway during takeoff.