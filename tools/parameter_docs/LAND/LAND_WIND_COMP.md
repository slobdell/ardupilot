---
layout: parameter
name: LAND_WIND_COMP
display_name: Land Wind Compensation
description: The percentage of wind speed to add to the landing airspeed target.
default_value: 0
range: 0 100
units: %
group: LAND
visual_asset_id: land_flare_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/Parameters.cpp#L100
---

# Land Wind Compensation (LAND_WIND_COMP)

## Description
`LAND_WIND_COMP` adds a safety margin for windy days.

If you are landing into a 20 m/s headwind, the ground speed will be very low. If the wind suddenly stops (wind shear), the plane might stall. This parameter tells the autopilot to fly faster than normal when it detects strong wind.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled).
*   **50%:** If wind is 10 m/s, add 5 m/s to the landing speed.
*   **Recommendation:** Set to **30-50%** for reliable all-weather operation.