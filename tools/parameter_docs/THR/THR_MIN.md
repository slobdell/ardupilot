---
layout: parameter
title: THR_MIN
name: Minimum Throttle
group: THR
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/Parameters.cpp#L916
---

# THR_MIN: Minimum Throttle

## Description
Minimum throttle percentage used in all modes except manual, provided THR_PASS_STAB is not set.

## Values
- **Range:** -100 to 100
- **Units:** %
- **Default:** 0

## Description
This parameter sets the "Floor" for the autopilot's throttle output.

- **Plane:**
    - **0:** Motor stops when throttle is cut.
    - **> 0 (e.g. 10):** Motor idles at 10% whenever armed, preventing the engine from quitting in flight (common for gas engines).
    - **< 0:** Allows Reverse Thrust (if supported by ESC/Prop).
- **Rover:**
    - Determines the minimum speed for autonomous driving.
- **Safety:** Ensure this is not set so high that the vehicle moves when armed on the ground.
