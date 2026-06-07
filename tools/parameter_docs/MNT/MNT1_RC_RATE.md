---
layout: parameter
name: MNT1_RC_RATE
display_name: Mount RC Rate (Instance 1)
description: Sets the maximum rotation speed when controlling the gimbal via RC sticks or knobs.
default_value: 0
range: 0 90
units: deg/s
group: MNT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Mount/AP_Mount_Params.cpp#L32
---

# Mount RC Rate (MNT1_RC_RATE)

## Description
`MNT1_RC_RATE` determines how fast your camera gimbal tilts or pans when you move the knobs on your transmitter.

*   **Non-Zero Value (1-90):** Enables **Rate Control**. Moving the knob away from the center makes the gimbal start moving in that direction. The farther you move the knob, the faster it rotates (up to this limit). Returning the knob to the center stops the movement.
*   **Zero (0):** Enables **Angle Control**. The gimbal's angle directly matches the position of the knob (e.g., knob at 10 o'clock = camera at -45 degrees).

## Tuning & Behavior
*   **Default:** 0 (Angle Control).
*   **Recommendation:** Use **Rate Control** (e.g., 20 or 30 deg/s) for cinematic filming, as it allows for much smoother starts and stops. Use **Angle Control** (0) if you need the camera to instantly point where your switch/knob is located.