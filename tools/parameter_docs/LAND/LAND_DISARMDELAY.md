---
layout: parameter
name: LAND_DISARMDELAY
display_name: Land Disarm Delay
description: The delay (in seconds) after detecting a successful landing before the motors disarm.
default_value: 20
range: 0 127
units: s
group: LAND
visual_asset_id: land_disarm_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduCopter/Parameters.cpp#L100
---

# Land Disarm Delay (LAND_DISARMDELAY)

## Description
`LAND_DISARMDELAY` is the "settling time" for the Land Detector.

After the sensors think the drone has touched the ground (Velocity = 0, Throttle = Min), the autopilot waits this many seconds to be *sure* before killing the motors.

## Tuning & Behavior
*   **Default Value:** 20 seconds (Fixed Wing). For Copter, this is usually `DISARM_DELAY` (default 2s).
*   **Recommendation:**
    *   **Fixed Wing:** 20s allows for taxiing or stopping.
    *   **Copter:** 2s prevents tip-overs.