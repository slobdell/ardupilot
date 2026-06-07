---
layout: parameter
name: MOT_SPD_SCA_BASE
display_name: Ground Speed Steering Scale Base
description: The ground speed (in m/s) above which steering sensitivity begins to be reduced to maintain high-speed stability.
default_value: 1.0
range: 0 10.0
units: m/s
group: MOT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AR_Motors/AP_MotorsUGV.cpp#L97
---

# Ground Speed Steering Scale Base (MOT_SPD_SCA_BASE)

## Description
`MOT_SPD_SCA_BASE` is a safety feature for Rovers and Boats that prevents high-speed rollovers or loss of control.

At low speeds (e.g., 1 m/s), you want 100% steering authority to make tight turns. At high speeds (e.g., 10 m/s), a full-lock steering command would cause the vehicle to flip or spin violently. This parameter defines the "Safe Speed" – above this speed, the autopilot automatically reduces the steering multiplier so that the vehicle remains stable.

## Tuning & Behavior
*   **Default:** 1.0 m/s.
*   **Recommendation:** Set this to the maximum speed at which your vehicle can safely handle a full-lock turn.
*   **Effect:** As speed increases above this base, the steering response becomes progressively "softer" or less sensitive.
*   **0:** Disables speed-based steering scaling.