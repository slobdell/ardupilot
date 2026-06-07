---
layout: parameter
name: FLAP_1_PERCNT
display_name: Automatic Flap Percentage (Stage 1)
description: The amount of flap deflection (in percent) applied when the aircraft drops below the first speed threshold.
default_value: 0
range: 0 100
units: %
group: FLAP
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduPlane/Parameters.cpp#L698
---

# Automatic Flap Percentage (Stage 1) (FLAP_1_PERCNT)

## Description
`FLAP_1_PERCNT` automates the first stage of flap deployment for fixed-wing aircraft.

Flaps are used to increase lift at low airspeeds. ArduPilot can automatically lower the flaps based on the current airspeed. This parameter sets how far the flaps should move (from 0% retracted to 100% full flaps) when the plane slows down below the [FLAP_1_SPEED](FLAP_1_SPEED.html).

## Tuning & Behavior
*   **0:** Disables automatic flaps.
*   **Value (%):** The target deflection. For example, setting this to **30** will lower the flaps 30% of their total range when the plane is slow.
*   **Logic Link:** Used primarily in CRUISE, FBWB, and AUTO modes.