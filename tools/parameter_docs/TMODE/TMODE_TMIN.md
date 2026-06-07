---
layout: parameter
name: TMODE_TMIN
display_name: Toy Mode Min Thrust Multiplier
description: The thrust scaling factor applied when the battery voltage is at its highest (full charge).
default_value: 1.0
range: 0.1 1.0
units: 
group: TMODE
visual_asset_id: tmode_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduCopter/toy_mode.cpp#L142
---

# Toy Mode Min Thrust Multiplier (TMODE_TMIN)

## Description
`TMODE_TMIN` is used in **Toy Mode** to ensure the drone's throttle feel remains consistent even as the battery drains.

A fully charged battery produces more power than a low battery. To prevent the drone from feeling "hyper" at the start of a flight and "sluggish" at the end, Toy Mode scales the thrust. `TMIN` defines the scaling factor applied at the **Maximum** voltage.

*   **1.0 (Default):** No scaling.
*   **0.8:** Reduces the motor power to 80% when the battery is full.

## Tuning & Behavior
*   **Default:** 1.0.
*   **Recommendation:** Leave at 1.0 unless you find the drone is too difficult to control with a fresh battery.
*   **Integration:** Works in conjunction with [TMODE_TMAX](TMODE_TMAX.html).