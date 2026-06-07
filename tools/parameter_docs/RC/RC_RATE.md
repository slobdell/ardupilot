---
layout: parameter
name: MNT1_RC_RATE
display_name: Mount RC Rate
description: Maximum rotation rate (in degrees per second) allowed when controlling the gimbal via RC sticks.
default_value: 0
range: 0 90
units: deg/s
group: RC
visual_asset_id: mount_rc_rate_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Mount/AP_Mount_Params.cpp#L32
---

# Mount RC Rate (MNT1_RC_RATE)

## Description
`MNT1_RC_RATE` (often appearing in older configs as `RC_RATE`) controls how fast your camera gimbal rotates when you move the knobs or sticks on your transmitter.

*   **0 (Disabled):** The gimbal is in **Position Mode**. If you move the knob to the middle, the camera points to the middle. If you let go, it stays where the knob is.
*   **> 0:** The gimbal is in **Rate Mode**. The knob acts like a joystick. Moving it slightly makes the gimbal turn slowly; moving it all the way makes it turn at the maximum rate defined by this parameter. Letting go of the stick stops the rotation, and the gimbal stays at its current angle.

## The Engineer's View
Defined in `AP_Mount_Params.cpp`.
This parameter selects between two fundamental control philosophies for cinematography. Most professional aerial photographers prefer **Rate Mode** because it allows for perfectly smooth, consistent panning speeds.

## Tuning & Behavior
*   **Default Value:** 0 (Position Mode)
*   **Recommendation:**
    *   **Cinematography:** Set to **10 or 20 deg/s** for cinematic pans.
    *   **FPV / Tracking:** Use **Position Mode (0)** so the camera direction matches your stick position exactly.