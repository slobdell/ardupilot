---
layout: parameter
name: WVANE_TAKEOFF
display_name: Weathervaning Takeoff Enable
description: Enables weathervaning immediately upon takeoff.
default_value: 0
range: 0 1
units: 
group: WVANE
visual_asset_id: wvane_enable_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_WeatherVane.cpp#L100
---

# Weathervaning Takeoff Enable (WVANE_TAKEOFF)

## Description
`WVANE_TAKEOFF` allows the drone to automatically rotate to face the wind as soon as it leaves the ground. This ensures that the climb-out phase of a mission is as efficient and stable as possible.