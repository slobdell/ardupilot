---
layout: parameter
name: Q_VFWD_ALT
display_name: QuadPlane Forward Motor Altitude
description: The minimum altitude (in meters) above home where forward motor assistance is active.
default_value: 0
range: 0 100
units: m
group: Q
visual_asset_id: vtol_vfwd_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# QuadPlane Forward Motor Altitude (Q_VFWD_ALT)

## Description
`Q_VFWD_ALT` prevents the forward pusher motor from spinning up while the drone is still taking off or low to the ground.

## Tuning & Behavior
*   **Default Value:** 0 (Active at all altitudes).
*   **Recommendation:** Set to **3 or 5 meters** to ensure the drone is clear of grass and ground personnel before the main propeller starts.