---
layout: parameter
name: WVANE_LAND
display_name: Weathervaning Land Enable
description: Enables weathervaning during the final landing phase of a mission.
default_value: 0
range: 0 1
units: 
group: WVANE
visual_asset_id: wvane_enable_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_WeatherVane.cpp#L100
---

# Weathervaning Land Enable (WVANE_LAND)

## Description
`WVANE_LAND` determines if the drone should face into the wind while it is touching down. This is highly recommended for QuadPlanes, as landing with a strong tailwind or crosswind can cause the drone to tip over or lose stability just as the motors spool down.