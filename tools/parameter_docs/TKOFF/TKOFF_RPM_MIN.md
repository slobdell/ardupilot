---
layout: parameter
name: TKOFF_RPM_MIN
display_name: Takeoff RPM Minimum
description: The minimum RPM required from the motors before a takeoff is permitted. Ensures all motors are spinning and healthy.
default_value: 0
range: 0 5000
units: RPM
group: TKOFF
visual_asset_id: takeoff_sequence_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduCopter/takeoff_check.cpp#L45
---

# Takeoff RPM Minimum (TKOFF_RPM_MIN)

## Description
`TKOFF_RPM_MIN` is a safety gate for drones with ESC Telemetry (BLHeli_32/AM32).

Before the drone leaves the ground in Auto mode, it checks that all motors are actually spinning. If any motor reports an RPM lower than this value, the takeoff is aborted. This prevents "Flip on Takeoff" crashes caused by a dead motor or a desync.

## The Engineer's View
Used in `ArduCopter/takeoff_check.cpp`.
The autopilot queries `AP_ESC_Telem` for the RPM of all active motors.
If `RPM < TKOFF_RPM_MIN`, the takeoff is held.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled).
*   **Recommendation:** Set to a value slightly below your idle RPM.
    *   **5" Quad:** Idle is ~1500 RPM. Set to **1000**.
    *   **Large Quad:** Idle is ~800 RPM. Set to **500**.