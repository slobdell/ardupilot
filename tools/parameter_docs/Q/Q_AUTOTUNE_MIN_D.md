---
layout: parameter
name: Q_AUTOTUNE_MIN_D
display_name: QuadPlane Autotune Minimum D
description: The minimum D-gain that the autotuner is allowed to set.
default_value: 0.001
range: 0 0.005
units: 
group: Q
visual_asset_id: autotune_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# QuadPlane Autotune Minimum D (Q_AUTOTUNE_MIN_D)

## Description
`Q_AUTOTUNE_MIN_D` prevents the autotuner from creating a sloppy, undamped tune.

Sometimes, a noisy frame tricks the autotuner into thinking the D-gain (Damping) is causing vibration, so it reduces D to near zero. This results in a drone that wobbles uncontrollably. This parameter sets a "floor" that the D-gain cannot drop below.

## Tuning & Behavior
*   **Default Value:** 0.001
*   **Recommendation:** Leave at default unless you have extremely noisy motors.