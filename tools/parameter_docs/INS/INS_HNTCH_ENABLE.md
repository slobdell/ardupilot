---
layout: parameter
name: INS_HNTCH_ENABLE
display_name: Harmonic Notch Filter Enable
description: Enables or disables the Harmonic Notch Filter system for surgical vibration reduction.
default_value: 0
range: 0 1
units: 
group: INS
visual_asset_id: notch_filter_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_InertialSensor/AP_InertialSensor.cpp#L100
---

# Harmonic Notch Filter Enable (INS_HNTCH_ENABLE)

## Description
`INS_HNTCH_ENABLE` activates the most advanced vibration-fighting tool in ArduPilot: the **Harmonic Notch Filter**.

Standard low-pass filters are like a broad-brush; they smooth everything. A Notch Filter is like a scalpel; it targets one specific frequency (the one caused by your spinning motors) and removes it while leaving everything else untouched.

Enabling this allows the drone to ignore the "buzz" of its own motors, leading to much cooler motors and smoother flight.

## The Engineer's View
Defined in `AP_InertialSensor.cpp`. 
When enabled, the autopilot allocates resources for a dynamically-tuned notch filter on the gyroscope data path. This filter is placed *after* the raw sampling but *before* the Rate PIDs.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled)
*   **Recommendation:** Every serious drone pilot should enable this. It is a game-changer for flight quality.
*   **Reboot Required:** Yes.
