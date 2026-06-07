---
layout: parameter
name: TECS_LAND_SINK
display_name: Sink Rate for Final Landing Stage
description: The target descent rate (in meters per second) during the final flare stage of an automatic landing.
default_value: 0.25
range: 0.0 2.0
units: m/s
group: TECS
visual_asset_id: landing_flare_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_TECS/AP_TECS.cpp#L162
---

# Sink Rate for Final Landing Stage (TECS_LAND_SINK)

## Description
`TECS_LAND_SINK` is the "Soft Landing" target.

When the plane is just a few meters above the ground, it enters the **Flare** stage. Instead of following a steep glide slope, it aims for this very gentle descent rate to ensure it touches down without bouncing or breaking the landing gear.

*   **0.25 (Default):** A very soft touchdown (0.5 knots descent).
*   **0.5:** A firm landing. Good for rough grass where you want the wheels to dig in.

## Tuning & Behavior
*   **Default Value:** 0.25 m/s.
*   **Recommendation:** If your plane consistently "Floats" and refuses to touch down, increase this to **0.5**. If your plane "Slam-Lands" and bounces, decrease to **0.15**.
