---
layout: parameter
name: Q_MAV_TYPE
display_name: MAVLink type identifier
description: Overrides the vehicle type reported in MAVLink HEARTBEAT messages.
default_value: 0
range: 0 21
units: 
group: Q
visual_asset_id: q_mav_type_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L254
---

# MAVLink type identifier (Q_MAV_TYPE)

## Description
`Q_MAV_TYPE` tells your Ground Control Station (GCS) what icon to display for your vehicle.

*   **0: AUTO (Default).** ArduPilot decides based on the frame class (usually reports as "FIXED_WING").
*   **20: VTOL_QUADROTOR.** Reports as a VTOL QuadPlane.
*   **21: VTOL_TILTROTOR.** Reports as a Tiltrotor.

## The Engineer's View
Some GCS software (like QGroundControl) changes its available flight modes or UI layout based on the reported MAV_TYPE. For example, if reported as "FIXED_WING", QGC might hide the "Takeoff" button slider that is normally present for Copters.

## Tuning & Behavior
*   **Default Value:** 0
*   **Recommendation:** Leave at **0** unless your GCS is not displaying the correct vehicle icon or options.