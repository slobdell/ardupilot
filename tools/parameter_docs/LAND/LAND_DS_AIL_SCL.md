---
layout: parameter
name: LAND_DS_AIL_SCL
display_name: Deepstall Aileron Gain Scaling
description: A scalar multiplier to reduce or increase aileron control authority during a deepstall landing.
default_value: 1.0
range: 0 2.0
units: 
group: LAND
visual_asset_id: deepstall_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Landing/AP_Landing_Deepstall.cpp#L129
---

# Deepstall Aileron Gain Scaling (LAND_DS_AIL_SCL)

## Description
`LAND_DS_AIL_SCL` adjusts how much the ailerons move to steer the plane while it is stalling.

In a deep stall, the wing is fully stalled, so ailerons might work differently (often reversed or less effective). This parameter allows you to tweak the steering aggression specifically for this flight phase without messing up your normal flight PID gains.

## Tuning & Behavior
*   **Default Value:** 1.0 (No change).
*   **Recommendation:** If the plane oscillates in roll while falling, reduce to **0.5**.