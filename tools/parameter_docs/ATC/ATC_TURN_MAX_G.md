---
layout: parameter
name: ATC_TURN_MAX_G
display_name: Turning maximum G force
description: The maximum lateral acceleration (in Gs) allowed during turns to prevent rollovers or loss of traction.
default_value: 0.6
range: 0.1 10.0
units: gravities
group: ATC
visual_asset_id: atc_turn_max_g_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/APM_Control/AR_AttitudeControl.cpp#L420
---

# Turning maximum G force (ATC_TURN_MAX_G)

## Description
`ATC_TURN_MAX_G` is the "Anti-Rollover" setting for rovers and boats.

When a vehicle turns at high speed, centrifugal force pushes it sideways. If this force is too high, a car might flip over, or a boat might slide (drift) uncontrollably. This parameter caps that force. If the rover is driving fast, the autopilot will automatically widen its turns to ensure the lateral force never exceeds this limit.

*   **Low Value (e.g. 0.3):** Safe, slow turns. Good for top-heavy trucks or tractors.
*   **High Value (e.g. 1.5):** Aggressive, sharp turns. Good for low-slung racing cars with high-grip tires.

## The Mathematics
The maximum turn rate ($\omega_{max}$) is calculated from the current speed ($V$) and the G-limit ($A_{max\_g}$):

$$ \omega_{max} = \frac{A_{max\_g} \cdot g}{V} $$

As speed $V$ increases, the allowed turn rate $\omega$ must decrease to stay under the G-limit.

## Tuning & Behavior
*   **Default Value:** 0.6 G.
*   **Recommendation:**
    *   **Ackermann Car:** Set to the point where the tires just start to squeal or the car feels "tippy."
    *   **Boat:** Set to 0.3-0.5 to prevent massive heel angles.
    *   **Skid-Steer:** Usually set high (1.0+) as they are typically low-profile and stable.