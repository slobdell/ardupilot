---
layout: parameter
name: SOAR_DIST_AHEAD
display_name: Soaring Thermal Entry Look-Ahead
description: Initial estimate of the distance (in meters) to the center of a detected thermal.
default_value: 5.0
range: 0 100
units: m
group: SOAR
visual_asset_id: soaring_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Soaring/AP_Soaring.cpp#L56
---

# Soaring Thermal Entry Look-Ahead (SOAR_DIST_AHEAD)

## Description
`SOAR_DIST_AHEAD` defines the "Starting Guess" for the autopilot when it first detects a thermal.

When the Variometer (climb rate sensor) indicates lift, the autopilot knows it is near a thermal, but it doesn't know exactly where the center is. This parameter tells the aircraft to assume the thermal core is this many meters directly ahead. The aircraft will then begin a turn toward that estimated spot. As it circles, the EKF updates this estimate based on the actual lift experienced.

## Tuning & Behavior
*   **Default:** 5.0 meters.
*   **Recommendation:** Leave at **5.0** for most small electric gliders. For larger, faster aircraft, you may need to increase this to **10.0 or 15.0** to account for the larger turning radius.
*   **Significance:** Correct initialization leads to faster "centering" of the thermal and better climb rates.