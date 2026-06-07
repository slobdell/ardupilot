---
layout: parameter
name: YAW2SRV_INT
display_name: Sideslip Control Integrator
description: Long-term rudder trim to eliminate persistent sideslip error.
default_value: 0
range: 0 2.0
units: 
group: YAW2SRV
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/APM_Control/AP_YawController.cpp#L44
---

# Sideslip Control Integrator (YAW2SRV_INT)

## Description
`YAW2SRV_INT` (Integral) eliminates long-term steady-state sideslip.

While `YAW2SRV_DAMP` reacts to sudden movements, and `YAW2SRV_SLIP` reacts to lateral forces, the Integrator term looks at persistent errors. If the plane is consistently flying with its tail slightly to one side (e.g. due to a slightly crooked vertical fin or asymmetric motor thrust), the Integrator will slowly "build up" and apply a constant rudder trim to straighten the aircraft.

## Tuning & Behavior
*   **Default:** 0.
*   **Recommendation:** Start with a very small value (e.g. **0.05** or **0.1**). 
*   **Effect:** Too much integrator will cause the tail to "Wander" or hunt slowly left and right. Too little will leave the plane flying "crabbed" through the air.