---
layout: parameter
name: MANUAL_OPTIONS
display_name: Manual Mode Options
description: Bitmask for configuring behavior in MANUAL flight mode (e.g., Steering scaling).
default_value: 0
range: 0 1
units: Bitmask
group: MANUAL
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/Rover/Parameters.cpp#L668
---

# Manual Mode Options (MANUAL_OPTIONS)

## Description
`MANUAL_OPTIONS` provides specialized behaviors for the **MANUAL** drive mode, primarily on Rovers.

*   **Bit 0 (1): Enable Steering Speed Scaling.** When enabled, the steering sensitivity is automatically reduced as the vehicle goes faster. This prevents high-speed "twitchiness" and rollovers caused by sudden sharp turns at full throttle.

## Tuning & Behavior
*   **Default:** 0 (Full sensitivity at all speeds).
*   **Recommendation:** Enable this if you find your Rover difficult to drive straight at high speeds.