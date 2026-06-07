---
layout: parameter
name: Q_FRAME_CLASS
display_name: QuadPlane Frame Class
description: Defines the physical arrangement of the VTOL lift motors (e.g., Quad, Hexa, Octa, Tailsitter).
default_value: 1
range: 0 17
units: 
group: Q
visual_asset_id: q_frame_class_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L129
---

# QuadPlane Frame Class (Q_FRAME_CLASS)

## Description
`Q_FRAME_CLASS` tells the autopilot how many vertical lift motors you have and how they are arranged. This corresponds exactly to the `FRAME_CLASS` used in ArduCopter.

*   **1: Quad.** 4 Motors in a square/rectangle. (Standard QuadPlane).
*   **2: Hexa.** 6 Motors.
*   **3: Octa.** 8 Motors.
*   **7: Tri.** 3 Motors (Tricopter layout).
*   **10: Tailsitter.** (Duo/Quad). The entire plane sits vertically on its tail for takeoff.

## The Engineer's View
Used to initialize the `AP_Motors` matrix. 
For **Tilt-Rotors** (like the V-22 Osprey or Convergence), you typically select the class that matches the number of *rotors* (e.g., **Tri** for a Convergence), and then use `Q_TILT_MASK` to define which ones can tilt.

## Tuning & Behavior
*   **Default Value:** 1 (Quad)
*   **Reboot Required:** Yes.
*   **Safety:** If set incorrectly (e.g., Hexa on a Quad), the motor mixing will be wrong, likely causing an immediate flip on takeoff.