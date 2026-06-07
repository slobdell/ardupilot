---
layout: parameter
name: Q_RTL_MODE
display_name: VTOL RTL mode
description: Controls whether Return to Launch (RTL) behaves like a plane or a multicopter.
default_value: 0
range: 0 3
units: 
group: Q
visual_asset_id: q_rtl_mode_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L198
---

# Q_RTL_MODE: VTOL RTL mode

## Description
Controls whether Return to Launch (RTL) behaves like a plane or a multicopter.

## Description
`Q_RTL_MODE` decides how your QuadPlane comes home when you trigger an RTL (or when failsafe triggers it).

*   **0: Disabled (Default).** Standard Plane RTL. The aircraft circles the home point at `RTL_ALTITUDE`. It will **NOT land**. You must take manual control to land it.
*   **1: Enabled (Hybrid).** Plane RTL to home. Once within `RTL_RADIUS`, it switches to VTOL (QRTL) and lands vertically.
*   **3: QRTL Always.** Immediately switches to VTOL mode and flies home like a multicopter. (Very inefficient for long range!).

## The Engineer's View
Option **1 (Hybrid)** is the standard "Fire and Forget" safety mode. It uses the efficiency of the wing to get home, then the precision of the quad motors to land.

## Tuning & Behavior
*   **Default Value:** 0
*   **Recommendation:** Set to **1** for autonomous safety.
*   **Danger:** If you set this to **3** and you are 5km away, the drone will try to fly 5km in hover mode. It will likely run out of battery and crash before it gets there.