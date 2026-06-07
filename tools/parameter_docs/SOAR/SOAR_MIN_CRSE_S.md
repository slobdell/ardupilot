---
layout: parameter
name: SOAR_MIN_CRSE_S
display_name: Minimum Soaring Cruise Time
description: The minimum time (in seconds) to remain in glide mode after exiting a thermal.
default_value: 10
range: 0 600
units: s
group: SOAR
visual_asset_id: soaring_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Soaring/AP_Soaring.cpp#L72
---

# Minimum Soaring Cruise Time (SOAR_MIN_CRSE_S)

## Description
`SOAR_MIN_CRSE_S` prevents the glider from "Hunting" or flickering between thermalling and cruising states.

When the glider leaves a thermal, it enters the **Cruise** (glide) mode to head toward the next waypoint. This parameter ensures it stays in that mode for a minimum amount of time before it is allowed to search for or enter a new thermal. This prevents the plane from circling in weak, broken lift immediately after exiting a good thermal.

## Tuning & Behavior
*   **Default:** 10 seconds.
*   **Recommendation:** Leave at **10-15 seconds**.
*   **Significance:** Ensures the aircraft gains enough horizontal distance from the previous thermal's turbulence before attempting to detect the next one.