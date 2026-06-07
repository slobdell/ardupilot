---
layout: parameter
name: TKOFF_RPM_MAX
display_name: Takeoff RPM Maximum
description: The maximum RPM allowed during the takeoff check. Helps detect if a propeller has come loose or is missing.
default_value: 0
range: 0 20000
units: RPM
group: TKOFF
visual_asset_id: takeoff_sequence_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduCopter/takeoff_check.cpp#L45
---

# Takeoff RPM Maximum (TKOFF_RPM_MAX)

## Description
`TKOFF_RPM_MAX` detects "Free-Spinning" motors.

If a propeller nut comes loose, the motor shaft will spin up to a very high RPM because it has no load. This parameter detects that condition and prevents the drone from attempting to fly with a loose prop.

## The Engineer's View
Used in `ArduCopter/takeoff_check.cpp`.
If `RPM > TKOFF_RPM_MAX`, the takeoff is aborted.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled).
*   **Recommendation:** Set to a value slightly above your hover RPM, but below your max RPM.
    *   **5" Quad:** Hover ~5000-8000 RPM. Max ~30k. Set check to **10000**.