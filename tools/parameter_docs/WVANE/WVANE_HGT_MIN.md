---
layout: parameter
name: WVANE_HGT_MIN
display_name: Weathervaning Minimum Height
description: The minimum height (in meters) above the ground required before automatic weathervaning is enabled.
default_value: 0
range: 0 100
units: m
group: WVANE
visual_asset_id: wvane_enable_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_WeatherVane.cpp#L100
---

# Weathervaning Minimum Height (WVANE_HGT_MIN)

## Description
`WVANE_HGT_MIN` prevents the drone from rotating while it is still very close to the ground. This ensures that the drone is safely clear of landing pads, grass, or personnel before it begins its automatic alignment with the wind.