---
layout: parameter
name: GROUND_STEER_DPS
display_name: "Ground steer rate"
description: "Maximum turn rate for ground steering servo"
default_value: 90
range: 10 360
units: "deg/s"
group: GROUND
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/Parameters.cpp#L614
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Ground steer rate (GROUND_STEER_DPS)

## Description
This parameter limits how fast the nose wheel (or tail wheel) servo can move. By slewing the steering command, it prevents the pilot from commanding an instantaneous, sharp turn that could cause the aircraft to tip over (wingtip strike) or skid during high-speed taxiing.

## The Mathematics
Rate Limiter:
$$ \frac{\Delta \text{Steer Angle}}{\Delta t} \le \text{GROUND_STEER_DPS} $$

## The Engineer's View
Defined in `ArduPlane/Parameters.cpp`.

## Tuning & Behavior
*   **Default Value:** 90 deg/s
*   **Adjustment:** Decrease for top-heavy aircraft or narrow gear widths. Increase for agile ground handling at low speeds.