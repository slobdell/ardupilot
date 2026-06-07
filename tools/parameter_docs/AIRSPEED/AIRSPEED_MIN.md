---
layout: parameter
name: AIRSPEED_MIN
display_name: Minimum Airspeed
description: The minimum airspeed for autonomous flight. If airspeed drops below this then the plane will pitch down to maintain airspeed.
default_value: 9
range: 5 100
units: m/s
group: AIRSPEED
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduPlane/Parameters.cpp
---

# Minimum Airspeed (AIRSPEED_MIN)

## Description
Defines the lower bound for airspeed during autonomous flight. The flight controller will prioritize maintaining this airspeed by pitching the nose down if necessary.

## Tuning & Behavior
*   **Default Value:** 9 m/s (Approx. 17.5 knots)
*   **Range:** 5 to 100 m/s
*   **Must be set above the stall speed of the aircraft with a safe margin.**