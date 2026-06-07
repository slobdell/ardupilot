---
layout: parameter
name: OSD_W_RESTVOLT
display_name: OSD Resting Voltage Warning
description: The estimated resting voltage at which the OSD will start flashing a warning.
default_value: 10.0
range: 0 100
units: V
group: OSD
visual_asset_id: osd_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_OSD/AP_OSD.cpp#L208
---

# OSD Resting Voltage Warning (OSD_W_RESTVOLT)

## Description
`OSD_W_RESTVOLT` provides a "Smart" low-battery alarm.

Unlike a simple voltage alarm that might flash every time you punch the throttle (causing "voltage sag"), ArduPilot's EKF estimates the **Resting Voltage** – what the battery would show if the motors were off. This is a much more accurate representation of the remaining energy. When this resting estimate falls below this value, the voltage readout will flash.

## Tuning & Behavior
*   **Default:** 10.0V.
*   **Recommendation:** Set this to the same value as your [OSD_W_BATVOLT](OSD_W_BATVOLT.html). This ensures that you get a steady warning when the battery is truly empty, rather than a flickering one that only triggers under load.
*   **Benefit:** Prevents "Phantom" low-battery alarms during high-current maneuvers.