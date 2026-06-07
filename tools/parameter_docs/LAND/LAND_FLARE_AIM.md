---
layout: parameter
name: LAND_FLARE_AIM
display_name: Land Flare Aim Altitude
description: The target altitude (in meters) for the flare maneuver (usually negative).
default_value: 0
range: -1 1
units: m
group: LAND
visual_asset_id: land_flare_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/Parameters.cpp#L100
---

# Land Flare Aim Altitude (LAND_FLARE_AIM)

## Description
`LAND_FLARE_AIM` aims the flare path slightly underground.

By aiming for an altitude of **-0.5 meters** (half a meter below the runway), you ensure that the plane positively touches down rather than floating indefinitely just a few inches above the ground.

## Tuning & Behavior
*   **Default Value:** 0 m.
*   **Recommendation:** Set to **-0.5** or **-1.0** to reduce "Float" and force a touchdown.