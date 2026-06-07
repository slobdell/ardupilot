---
layout: parameter
name: Q_TKOFF_RPM_MAX
display_name: QuadPlane Takeoff RPM Max
description: The maximum RPM allowed during the takeoff phase.
default_value: 0
range: 0 20000
units: RPM
group: Q
visual_asset_id: vtol_takeoff_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# QuadPlane Takeoff RPM Max (Q_TKOFF_RPM_MAX)

## Description
`Q_TKOFF_RPM_MAX` caps the motor speed during launch.

This is useful for noise abatement or to protect fragile props from over-spinning during the high-power takeoff surge.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled).