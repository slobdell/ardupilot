---
layout: parameter
name: WVANE_VELZ_MAX
display_name: Weathervaning Max Vertical Speed
description: The maximum climb or descent rate (in m/s) at which automatic weathervaning is allowed to operate.
default_value: 0
range: 0 5
units: m/s
group: WVANE
visual_asset_id: wvane_enable_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_WeatherVane.cpp#L74
---

# Weathervaning Max Vertical Speed (WVANE_VELZ_MAX)

## Description
`WVANE_VELZ_MAX` sets a "Safety Cap" on weathervaning during climbs and descents.

If the drone is climbing or descending very fast, the aerodynamic forces on the airframe change significantly. This parameter ensures that the autopilot stops trying to rotate the drone into the wind if the vertical speed is too high, which could cause instability.

*   **0 (Default):** Always allowed (Disabled vertical speed limit).
*   **Recommendation:** Leave at **0** unless you notice heading instability specifically during fast climbs or descents.