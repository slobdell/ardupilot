---
layout: parameter
name: AIRSPEED_MAX
display_name: Maximum Airspeed
description: The maximum airspeed for autonomous flight. The plane will pitch up to stay below this airspeed.
default_value: 22
range: 5 100
units: m/s
group: AIRSPEED
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduPlane/Parameters.cpp
---

# Maximum Airspeed (AIRSPEED_MAX)

## Description
Defines the upper bound for airspeed during autonomous flight. The flight controller will prioritize staying below this airspeed by pitching the nose up if necessary.

## Tuning & Behavior
*   **Default Value:** 22 m/s (Approx. 43 knots)
*   **Range:** 5 to 100 m/s
*   **Should be set below the Vne (Never Exceed Speed) of the airframe.**