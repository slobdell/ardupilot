---
layout: parameter
name: LAND_DS_ABORTALT
display_name: Deepstall Abort Altitude
description: The minimum altitude (in meters) above home which the aircraft must be above to abort a deepstall landing.
default_value: 0
range: 0 50
units: m
group: LAND
visual_asset_id: deepstall_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Landing/AP_Landing_Deepstall.cpp#L125
---

# Deepstall Abort Altitude (LAND_DS_ABORTALT)

## Description
`LAND_DS_ABORTALT` defines the "Point of No Return" for deepstall landings.

Once the plane has stalled and is falling, it takes time and altitude to recover into forward flight. If you trigger an abort (Go Around) when the plane is too low, it will hit the ground before it can regain airspeed. This parameter prevents the autopilot from trying to recover if it is below this safety height.

## Tuning & Behavior
*   **Default Value:** 0 (Always allowed to try).
*   **Recommendation:** Set to the altitude it takes your plane to recover from a full stall plus 10 meters buffer (e.g. **20m**).