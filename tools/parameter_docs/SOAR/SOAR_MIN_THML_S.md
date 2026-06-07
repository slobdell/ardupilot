---
layout: parameter
name: SOAR_MIN_THML_S
display_name: Minimum Soaring Thermal Time
description: The minimum time (in seconds) to remain in a thermal after detection.
default_value: 20
range: 0 600
units: s
group: SOAR
visual_asset_id: soaring_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Soaring/AP_Soaring.cpp#L64
---

# Minimum Soaring Thermal Time (SOAR_MIN_THML_S)

## Description
`SOAR_MIN_THML_S` sets a "Timer" for how long the glider must commit to a thermal once it starts circling.

Thermals can be turbulent and noisy. Without this parameter, the autopilot might think it's found a thermal, circle once, and then immediately "Lose" it and exit because of a brief downdraft. This setting forces the plane to stay in the circling state for at least this many seconds, providing enough time for the climb rate filters to stabilize and confirm if the lift is genuine.

## Tuning & Behavior
*   **Default:** 20 seconds.
*   **Recommendation:** Keep at **20-30 seconds**. This is typically enough for one or two full circles, allowing the EKF and Soaring logic to build a reliable estimate of the thermal's strength and center.