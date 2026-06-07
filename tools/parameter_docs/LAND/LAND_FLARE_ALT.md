---
layout: parameter
name: LAND_FLARE_ALT
display_name: Land Flare Altitude
description: The altitude (in meters) at which the landing flare starts.
default_value: 3
range: 0 10
units: m
group: LAND
visual_asset_id: land_flare_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/Parameters.cpp#L100
---

# Land Flare Altitude (LAND_FLARE_ALT)

## Description
`LAND_FLARE_ALT` sets the "Pull Up" height for a fixed-wing autonomous landing.

As the plane approaches the runway, it flies a descending path. At this altitude, it stops following the path and starts the "Flare" (pulling the nose up to bleed off speed and descend very slowly until touchdown).

## Tuning & Behavior
*   **Default Value:** 3 meters.
*   **Recommendation:** Set to **2-4 meters** for most small UAVs.
*   **Too Low:** The plane will hit the ground before it can slow down (Hard landing).
*   **Too High:** The plane will "Float" above the runway for too long and might stall and drop.