---
layout: parameter
name: TECS_SYNAIRSPEED
display_name: Synthetic Airspeed Enable
description: Allows the autopilot to estimate airspeed using IMU and GPS data when no physical pitot tube is present.
default_value: 0
range: 0 1
units: 
group: TECS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_TECS/AP_TECS.cpp#L244
---

# Synthetic Airspeed Enable (TECS_SYNAIRSPEED)

## Description
`TECS_SYNAIRSPEED` allows the autopilot to "Guess" the airspeed using internal sensors (accelerometers, gyros, and GPS) instead of a physical pitot tube.

This is extremely useful for small or budget drones where mounting a pitot tube is difficult. However, it is **significantly less accurate** than a real sensor, especially in gusty conditions or during aggressive maneuvers, as it relies heavily on a perfect wind estimate.

## Tuning & Behavior
*   **0: Disabled (Default).** The autopilot will use its internal "Ground Speed to Airspeed" mapping or a physical sensor if available.
*   **1: Enabled.** The autopilot uses the EKF's synthetic airspeed estimate for longitudinal control.
*   **Warning:** Do not enable this unless you have verified that your drone has a stable and accurate wind estimate in flight. If the wind estimate is wrong, the synthetic airspeed will be wrong, which can lead to a stall or over-speed condition.