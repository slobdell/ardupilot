---
layout: parameter
name: LAND_PITCH_DEG
display_name: Land Flare Pitch Angle
description: The target pitch angle (in degrees) during the final flare.
default_value: 0
range: 0 15
units: deg
group: LAND
visual_asset_id: land_flare_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/Parameters.cpp#L100
---

# Land Flare Pitch Angle (LAND_PITCH_DEG)

## Description
`LAND_PITCH_DEG` sets the minimum nose-up attitude for touchdown.

This ensures the plane lands on its main wheels (for tricycle gear) or in a 3-point attitude (for taildraggers), protecting the propeller from striking the runway.

## Tuning & Behavior
*   **Default Value:** 0.
*   **Recommendation:** Set to **3-5 degrees** for most airframes.