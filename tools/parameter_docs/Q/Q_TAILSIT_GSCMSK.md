---
layout: parameter
name: Q_TAILSIT_GSCMSK
display_name: Tailsitter Gain Scaling Mask
description: A bitmask of control surfaces that will have their gains scaled by airspeed during tailsitter flight.
default_value: 0
range: 0 4294967295
units: 
group: Q
visual_asset_id: vtol_tailsitter_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# Tailsitter Gain Scaling Mask (Q_TAILSIT_GSCMSK)

## Description
`Q_TAILSIT_GSCMSK` protects against "Control Surface Flutter" during transitions.

In a hover, there is no airspeed, so the elevons/ailerons must move a lot to tilt the plane. As the plane speeds up, those same large movements would cause the plane to flip or vibrate violently. This parameter tells ArduPilot which surfaces need to be automatically "Dampened" as the plane gets faster.

*   **Bit 0 (1):** Roll
*   **Bit 1 (2):** Pitch
*   **Bit 2 (4):** Yaw

## Tuning & Behavior
*   **Default Value:** 0.
*   **Recommendation:** Usually set to **7** (Roll+Pitch+Yaw) for all tailsitters with control surfaces.