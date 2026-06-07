---
layout: parameter
name: TKOFF_DIST
display_name: Takeoff Completion Distance
description: Horizontal distance (in meters) from the takeoff point at which the takeoff is considered complete.
default_value: 200
range: 0 1000
units: m
group: TKOFF
visual_asset_id: takeoff_sequence_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/mode_takeoff.cpp#L43
---

# Takeoff Completion Distance (TKOFF_DIST)

## Description
`TKOFF_DIST` is a secondary exit condition for a takeoff. It ensures the drone transitions to its normal mission path even if it hasn't reached its target altitude (`TKOFF_ALT`) yet, but has flown a safe distance away from the launch site.

This is useful for prevent the drone from climbing endlessly in a straight line if it's having trouble reaching a high `TKOFF_ALT`.

*   **Default Value:** 200 meters.

## The Engineer's View
Used by the `ModeTakeoff` state machine.
The takeoff is marked as "Complete" if **either** of these conditions are met:
1.  Current Altitude $\geq$ `TKOFF_ALT`.
2.  Horizontal Distance from Start $\geq$ `TKOFF_DIST`.

## Tuning & Behavior
*   **Default Value:** 200 m.
*   **Recommendation:** Set this to roughly the size of your takeoff field. If you have a 500m long runway, set this to **300 or 400**.