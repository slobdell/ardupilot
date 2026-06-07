---
layout: parameter
name: Q_PILOT_SPD_DN
display_name: Pilot Maximum Descent Rate
description: The maximum vertical speed (in cm/s) for pilot-commanded descents in VTOL modes.
default_value: 0
range: 0 500
units: cm/s
group: Q
visual_asset_id: vtol_control_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# Pilot Maximum Descent Rate (Q_PILOT_SPD_DN)

## Description
`Q_PILOT_SPD_DN` sets the "Speed Limit" for going down in VTOL modes.

## Tuning & Behavior
*   **Default Value:** 0 (Uses `PILOT_SPEED_DN` or `Q_PILOT_SPD_UP` if 0).
*   **Recommendation:** Set to **150-200 cm/s** for safe landings. Descending too fast can cause the drone to wobble in its own rotor wash (Vortex Ring State).