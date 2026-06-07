---
layout: parameter
name: RNGFND_LANDING
display_name: Enable Rangefinder (Phase Specific)
description: Controls when the rangefinder data is used for flight control (Landing, Takeoff, Assist).
default_value: 0
range: 0 1
units: 
group: RNGFND
visual_asset_id: rngfnd_range_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduPlane/Parameters.cpp#L801
---

# Enable Rangefinder (Phase Specific) (RNGFND_LANDING)

## Description
`RNGFND_LANDING` is the master switch for integrating distance sensor data into the **Plane** and **QuadPlane** flight logic. 

Even if a rangefinder is configured and reporting data, ArduPilot will not use it for altitude control during landing or takeoff unless this parameter is set. This provides an safety layer, allowing pilots to verify sensor health before trusting it for critical landing maneuvers.

*   **0: Disabled.** Rangefinder data is logged but ignored for flight control.
*   **1: Enabled.** Used for landing approach, final flare, and VTOL assist.

## Tuning & Behavior
*   **Default:** 0.
*   **Safety:** Only enable this after verifying that your rangefinder reports accurate distances and doesn't "glitch" or drop out while the vehicle is in motion.