---
layout: parameter
name: Q_PILOT_SPD_UP
display_name: Pilot Maximum Climb Rate
description: The maximum vertical speed (in cm/s) for pilot-commanded climbs in VTOL modes.
default_value: 250
range: 50 1000
units: cm/s
group: Q
visual_asset_id: vtol_control_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# Pilot Maximum Climb Rate (Q_PILOT_SPD_UP)

## Description
`Q_PILOT_SPD_UP` sets the "Speed Limit" for going up in VTOL modes.

When you push the throttle stick to the maximum, the drone will climb at exactly this rate. This ensures predictable behavior and prevents the pilot from over-working the lift motors.

## Tuning & Behavior
*   **Default Value:** 250 cm/s (2.5 m/s).
*   **Recommendation:** Match this to your airframe's power-to-weight ratio. High-power quads can handle **500 or 1000 cm/s**.