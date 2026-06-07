---
layout: parameter
name: TECS_PTCH_FF_V0
display_name: Pitch Feed-Forward Reference Speed
description: The airspeed at which no predictive pitch adjustment is applied.
default_value: 12.0
range: 5.0 50.0
units: m/s
group: TECS
visual_asset_id: tecs_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_TECS/AP_TECS.cpp#L258
---

# Pitch Feed-Forward Reference Speed (TECS_PTCH_FF_V0)

## Description
`TECS_PTCH_FF_V0` provides the baseline for the [TECS_PTCH_FF_K](TECS_PTCH_FF_K.html) feature.

It represents the natural "Neutral Speed" of the aircraft – the speed at which it glides with a neutral pitch command. When the autopilot demands exactly this speed, no feed-forward correction is applied. If it demands more speed, it pitches down. If it demands less, it pitches up.

## Tuning & Behavior
*   **Default:** 12.0 m/s.
*   **Calibration:** Fly the plane in Manual or FBWA with neutral elevator trim and observe the resulting steady-state airspeed. Enter that value here.
*   **Requirement:** This parameter is only used if `TECS_PTCH_FF_K` is non-zero.