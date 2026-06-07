---
layout: parameter
name: Q_LAND_ICE_CUT
display_name: QuadPlane Land ICE Cut
description: The altitude (in meters) at which the internal combustion engine is killed during a VTOL landing.
default_value: 0
range: 0 10
units: m
group: Q
visual_asset_id: vtol_land_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# QuadPlane Land ICE Cut (Q_LAND_ICE_CUT)

## Description
`Q_LAND_ICE_CUT` automatically kills the gas engine during the final stage of a vertical landing.

This prevents the propeller from striking the ground if the plane tips over, and stops the engine from idling on the ground.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled).
*   **Recommendation:** Set to **2 meters** to cut the engine just before touchdown.