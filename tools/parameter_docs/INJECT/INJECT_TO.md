---
layout: parameter
name: INJECT_TO
display_name: "GPS Data Injection Target"
description: "Selects which GPS instance receives the RTK correction data sent via MAVLink."
default_value: 127
range: 0 127
units: "Index"
group: INJECT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_GPS/AP_GPS.cpp#L173
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# GPS Data Injection Target (INJECT_TO)

## Description
This parameter controls the routing of "GPS_INJECT_DATA" MAVLink packets. These packets are typically used to send RTK (Real-Time Kinematic) corrections from a Ground Control Station (GCS) to the autopilot, enabling centimeter-level positioning accuracy.

If your vehicle has multiple GPS sensors, you can use this parameter to decide if the corrections should go to a specific GPS instance (e.g., just the primary one) or be "broadcast" to all connected GPS modules simultaneously.

## The Mathematics
The value maps to the internal GPS instance index ($i$):
*   **0:** GPS 1 (First instance).
*   **1:** GPS 2 (Second instance).
*   **127:** All GPS instances (Broadcast mode).

## The Engineer's View
In `AP_GPS::handle_msg()` (`libraries/AP_GPS/AP_GPS.cpp`):
1.  The system receives raw serial data from the MAVLink `GPS_INJECT_DATA` or `GPS2_RTK` packets.
2.  It checks the `_inject_to` parameter.
3.  If set to **127** (`GPS_RTK_INJECT_TO_ALL`), it iterates through every detected GPS backend and calls `inject_data()`.
4.  If set to a specific index ($0$ or $1$), it sends the data *only* to that specific backend. 
5.  This ensures that if you have two different GPS models (e.g., a u-blox and a Septentrio) that require different correction formats, you can target the corrections appropriately (though most users simply broadcast to all).

## Tuning & Behavior
*   **Default Value:** 127 (All).
*   **Recommended:** Leave at **127** unless you have a specific dual-GPS setup where the sensors are of different types and sharing corrections causes errors.
*   **RTK Fix:** If your GCS shows "RTK Fixed" or "RTK Float" but only on one GPS, check this parameter to ensure it is set to include the second GPS instance if needed.

