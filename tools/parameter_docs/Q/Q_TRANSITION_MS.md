---
layout: parameter
name: Q_TRANSITION_MS
display_name: Transition time
description: The duration (in milliseconds) the VTOL motors remain active after the transition airspeed is reached.
default_value: 5000
range: 0 30000
units: ms
group: Q
visual_asset_id: q_transition_ms_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L44
---

# Transition time (Q_TRANSITION_MS)

## Description
`Q_TRANSITION_MS` is a safety buffer. 

When your QuadPlane accelerates forward, it waits until it reaches `ARSPD_FBW_MIN` (Minimum Airspeed). Once it hits that speed, the wing *should* be flying. However, to be safe, the autopilot keeps the VTOL motors running for this extra amount of time to ensure the wing is fully generating lift before shutting them down.

*   **5000ms (Default):** The quad motors stay on for 5 seconds after reaching minimum airspeed.

## The Engineer's View
Used in `SLT_Transition::update()`.
During this phase (`TRANSITION_TIMER`), the quad motors' throttle is linearly ramped down from hover power to zero. This provides a smooth handoff from rotor-borne lift to wing-borne lift.

## Tuning & Behavior
*   **Default Value:** 5000 ms
*   **Recommendation:** 
    *   **New Airframes:** Keep at **5000** or higher to be safe.
    *   **Tuned Aircraft:** You can reduce this to **2000** or **3000** to save battery and reduce drag during transition.
    *   **Warning:** Setting this too low (e.g., 0) can cause the plane to stall immediately after the transition if the airspeed sensor reading was momentarily noisy or if the wing wasn't truly ready.